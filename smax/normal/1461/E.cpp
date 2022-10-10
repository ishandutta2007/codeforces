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

bool vis[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    if (y <= x) {
        __int128 diff = r - k, need = min((__int128) y > diff ? (y - diff + x - 1) / x : 0, (__int128) t);
        if (need != 0 && (k - l) / need < x) {
            cout << "No\n";
        } else {
            k -= x * need;
            t -= need;
            cout << (k + y <= r && (x == y || t <= (k - l) / (x - y)) ? "Yes" : "No") << "\n";
        }
    } else {
        __int128 diff = r - k, need = min((__int128) y > diff ? (y - diff + x - 1) / x : 0, (__int128) t);
        if (need != 0 && (k - l) / need < x) {
            cout << "No\n";
        } else {
            k -= x * need;
            t -= need;
            bool ok = true;
            while (t > 0) {
                // decrease as much x as possible until we gonna drop out
                assert(l <= k && k <= r);
                __int128 dec = min((k - l) / x, t);
                k -= x * dec;
                t -= dec;
                if (t == 0)
                    break;
                if (!(k >= l && k - l < x))
                    while (true) {k++;}
                if (vis[k - l])
                    break;
                vis[k - l] = true;
                if (t == 0)
                    break;
                k += y;
                if (k > r) {
                    ok = false;
                    break;
                }
                k -= x;
                t--;
            }
            cout << (ok ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}