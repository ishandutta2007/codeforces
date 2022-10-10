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
        vector<int> a(n);
        map<int, int> cnt;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        map<int, set<int>> bad;
        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            bad[x].insert(y);
            bad[y].insert(x);
        }

        vector<vector<int>> groups(n + 1);
        for (int x : a)
            groups[cnt[x]].push_back(x);
        for (auto &v : groups) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }

        long long ret = 0;
        for (int i=1; i<=n; i++)
            if (!groups[i].empty())
                for (int j=1; j<=i; j++)
                    if (!groups[j].empty())
                        for (int x : groups[i]) {
                            int k = (int) groups[j].size() - 1;
                            while (k >= 0 && (x == groups[j][k] || (bad.count(x) && bad[x].count(groups[j][k]))))
                                k--;
                            if (k >= 0)
                                ret = max(ret, (long long) (i + j) * (x + groups[j][k]));
                        }
        cout << ret << "\n";
    }

    return 0;
}