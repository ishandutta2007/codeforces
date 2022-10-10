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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m), b(n * m);
        for (int i=0; i<n*m; i++) {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b.begin(), b.end());
        int r = 0, c = 0, ret = 0;
        map<int, vector<pair<int, int>>> mp;
        for (int i=0; i<n*m; ) {
            int j = i;
            while (j < n * m && b[i] == b[j])
                j++;
            int cnt = j - i;
            while (cnt > 0) {
                int fit = min(m - c, cnt);
                for (int k=c; k<c+fit; k++)
                    mp[b[i]].emplace_back(r, k);
                c += fit;
                if (c == m)
                    r++, c = 0;
                cnt -= fit;
            }
            i = j;
        }
        DEBUG(mp);

        for (auto &p : mp)
            sort(p.second.begin(), p.second.end(), [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first > b.first;
            });

        vector<vector<bool>> sit(n, vector<bool>(m));
        for (int x : a) {
            auto [i, j] = mp[x].back();
            mp[x].pop_back();
            for (int k=0; k<j; k++)
                ret += sit[i][k];
            sit[i][j] = true;
        }
        cout << ret << "\n";
    }

    return 0;
}