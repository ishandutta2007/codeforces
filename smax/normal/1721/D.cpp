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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;

        vector groups(1, make_pair(vector<int>(n), vector<int>(n)));
        iota(groups[0].first.begin(), groups[0].first.end(), 0);
        iota(groups[0].second.begin(), groups[0].second.end(), 0);
        int ret = 0;
        for (int i=29; i>=0; i--) {
            vector<pair<vector<int>, vector<int>>> ngroups;
            bool ok = true;
            for (const auto &v : groups) {
                pair<vector<int>, vector<int>> v01, v10;
                for (int x : v.first)
                    (a[x] >> i & 1 ? v10 : v01).first.push_back(x);
                for (int x : v.second)
                    (b[x] >> i & 1 ? v01 : v10).second.push_back(x);
                if (v01.first.size() != v01.second.size()) {
                    ok = false;
                    break;
                }
                if (!v01.first.empty())
                    ngroups.push_back(v01);
                if (!v10.first.empty())
                    ngroups.push_back(v10);
            }
            if (ok) {
                ret |= 1 << i;
                groups = move(ngroups);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}