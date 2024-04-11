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
        vector<int> a(n);
        vector<set<int>> pos(2);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] %= 2;
            pos[a[i]].insert(i);
        }

        if (abs((int) pos[0].size() - (int) pos[1].size()) > 1) {
            cout << "-1\n";
            continue;
        }

        // 0101...
        int ret1 = 0;
        vector<int> b = a;
        auto bpos = pos;
        for (int i=0; i<n; i++) {
            int x = i % 2;
            if (b[i] != x) {
                auto it = bpos[x].lower_bound(i);
                if (it == bpos[x].end()) {
                    ret1 = INT_MAX;
                    break;
                }
                ret1 += *it - i;
                swap(b[i], b[*it]);
                bpos[x ^ 1].insert(*it);
                bpos[x].erase(it);
            }
            DEBUG(i, ret1, b, bpos);
        }

        // 1010...
        int ret2 = 0;
        b = a;
        bpos = pos;
        for (int i=0; i<n; i++) {
            int x = (i + 1) % 2;
            if (b[i] != x) {
                auto it = bpos[x].lower_bound(i);
                if (it == bpos[x].end()) {
                    ret2 = INT_MAX;
                    break;
                }
                ret2 += *it - i;
                swap(b[i], b[*it]);
                bpos[x ^ 1].insert(*it);
                bpos[x].erase(it);
            }
        }

        DEBUG(ret1, ret2);
        cout << min(ret1, ret2) << "\n";
    }

    return 0;
}