#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i=1; i<=n; i++)
            cin >> a[i];

        vector<long long> pref(n + 1);
        vector<vector<long long>> mn(2, vector<long long>(n + 1, LLONG_MAX));
        for (int i=1; i<=n; i++) {
            pref[i] = -pref[i-1] + a[i];
            mn[i % 2][i] = pref[i];
        }

        vector<RMQ<long long>> rmq{mn[0], mn[1]};
        vector<vector<tuple<int, int, long long>>> queries(n + 1);
        for (int i=1; i<n; i++) {
            int l = i + 1, r = n + 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (rmq[m % 2].query(i, m) - (m % 2 == i % 2 ? -1 : 1) * pref[i-1] >= 0 && rmq[(m - 1) % 2].query(i, m - 1) - (m % 2 == i % 2 ? 1 : -1) * pref[i-1] >= 0)
                    l = m + 1;
                else
                    r = m;
            }
            DEBUG(a, i, l - 1);
            if (i < l - 1) {
                queries[i].emplace_back(i % 2, -1, pref[i-1]);
                queries[l-1].emplace_back(i % 2, 1, pref[i-1]);
            }
        }

        // want to count pairs where pref[i] - (i % 2 == p ? -1 : 1) * x == 0
        long long ret = count(a.begin(), a.end(), 0) - 1;
        vector<map<long long, int>> mp(2);
        for (int i=1; i<=n; i++) {
            mp[i % 2][pref[i]]++;
            for (auto [p, d, x] : queries[i]) {
                ret += d * (mp[p][-x] + mp[p^1][x]);
                DEBUG(i, p, d, x, ret);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}