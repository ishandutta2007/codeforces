#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        long long ret = LLONG_MAX;
        for (int mask=1; mask<1<<9; mask++) {
            int sum = 0;
            for (int i=0; i<9; i++)
                if (mask & (1 << i))
                    sum += i + 1;
            if (sum == x) {
                long long cur = 0;
                for (int i=0; i<9; i++)
                    if (mask & (1 << i))
                        cur = 10 * cur + i + 1;
                ret = min(ret, cur);
            }
        }
        cout << (ret == LLONG_MAX ? -1 : ret) << "\n";
    }

    return 0;
}