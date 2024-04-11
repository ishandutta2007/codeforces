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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++)
        cin >> p[i];

    vector<int> peaks, ls(n), rs(n);
    multiset<int> slopes;
    int cur = -1;
    bool valley = false;
    for (int i=0; i<n; i++) {
        cur++;
        if (i > 0 && i + 1 < n) {
            if (p[i-1] < p[i] && p[i] > p[i+1]) {
                peaks.push_back(i);
                slopes.insert(cur);
                ls[i] = cur;
                cur = 0;
                valley = false;
            } else if (p[i-1] > p[i] && p[i] < p[i+1]) {
                slopes.insert(cur);
                if (!peaks.empty())
                    rs[peaks.back()] = cur;
                cur = 0;
                valley = true;
            }
        }
    }
    if (cur > 0) {
        slopes.insert(cur);
        if (!peaks.empty() && !valley)
            rs[peaks.back()] = cur;
    }

    int ret = 0;
    for (int i : peaks) {
        slopes.erase(slopes.find(ls[i]));
        slopes.erase(slopes.find(rs[i]));
        bool fail = (!slopes.empty() && *slopes.rbegin() >= max(ls[i], rs[i]))
                  || ls[i] - (ls[i] % 2 == 0) >= rs[i] || rs[i] - (rs[i] % 2 == 0) >= ls[i];
        if (!fail)
            ret++;
        slopes.insert(ls[i]);
        slopes.insert(rs[i]);
    }
    cout << ret << "\n";

    return 0;
}