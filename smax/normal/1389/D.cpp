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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        long long intersect = max(min(r1, r2) - max(l1, l2), 0LL);
        if (intersect * n >= k) {
            cout << "0\n";
            continue;
        }

        k -= intersect * n;
        long long ret = 1e18, dist = max(l2 - r1, 0LL), canGrow = max(r1, r2) - min(l1, l2) - intersect;
        DEBUG(dist, canGrow)
        for (long long i=1; i<=n; i++) {
            long long cur = dist * i;
            if (k <= canGrow * i) {
                ret = min(ret, cur + k);
            } else {
                cur += canGrow * i;
                DEBUG(i, cur)
                long long ohK = k - canGrow * i;
                DEBUG(ohK)
                ret = min(ret, cur + ohK * 2);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}