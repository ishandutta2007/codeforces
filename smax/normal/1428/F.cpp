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

int maxL[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    memset(maxL, -1, sizeof(maxL));
    int i = 0;
    long long ret = 0, cur = 0;
    while (i < n) {
        if (s[i] == '0') {
            ret += cur;
            i++;
        } else {
            int l = i, r = i + 1;
            while (r < n && s[r] == '1')
                r++;
            for (int len=1; len<=r-l; len++) {
                cur += l + len - 1 - maxL[len];
                ret += cur;
                maxL[len] = r - len;
            }
            i = r;
        }
    }
    cout << ret << "\n";

    return 0;
}