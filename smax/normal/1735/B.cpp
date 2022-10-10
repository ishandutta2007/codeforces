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

int get(int x, int mn) {
    int l = 1, r = x + 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (mn * 2 <= (x + m - 1) / m)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn = INT_MAX;
        priority_queue<array<int, 3>> pq;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            mn = min(mn, a);
            pq.push({a, a, 1});
        }

        int ret = 0;
        while (mn * 2 <= pq.top()[0]) {
            auto [_, x, c] = pq.top();
            pq.pop();
            int nc = get(x, mn);
            mn = min(mn, x / nc);
            ret += nc - c;
            pq.push({(x + nc - 1) / nc, x, nc});
        }
        cout << ret << "\n";
    }

    return 0;
}