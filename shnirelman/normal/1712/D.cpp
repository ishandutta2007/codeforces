#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<pii> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        b[i] = {a[i], i};
    }

    sort(b.begin(), b.end());

    int mx = 1000'000'000;

    for(int i = 0; i < k - 2; i++) {
        a[b[i].s] = mx;
    }

    int nxt = max(k - 2, 0);

    int ans = 0;

//    for(int mask = 0; mask < 4; mask++) if(__builtin_popcount(mask) <= k) {
    for(int mask = 3; mask >= 0; mask--) if(__builtin_popcount(mask) <= k) {
//        cout << mask << endl;
//        if(mask != 1 && k - 3 + __builtin_popcount(mask) >= 0)
//            a[b[k - 3 + __builtin_popcount(mask)].s] = mx;

//        for(int x : a)
//            cout << x << ' ';
//        cout << endl;

        vector<int> p(n + 1, mx), s(n + 1, mx);
        for(int i = 0; i < n; i++) {
            p[i + 1] = min(p[i], a[i]);
        }

        for(int i = n - 1; i >= 0; i--) {
            s[i] = min(s[i + 1], a[i]);
        }

        for(int i = 0; i < n - 1; i++) {
            int x = (mask % 2 == 0 ? a[i] : mx);
            int y = (mask / 2 == 0 ? a[i + 1] : mx);

            int pref = 0;
            pref = min(p[i], x) + min({p[i], x, y});


//            if(mask % 2 == 0) {
//                pref += p[i + 1];
//                if(mask / 2 == 0)
//                    pref += p[i + 2];
//                else
//                    pref += p[i + 1];
//            } else {
//                pref += p[i];
//                if(mask / 2 == 0)
//                    pref += min(p[i], a[i + 1]);
//                else
//                    pref += p[i];
//            }

            int suf = 0;
            suf = min(s[i + 2], y) + min({s[i + 2], x, y});
//            if(mask / 2 == 0) {
//                suf += s[i + 1];
//                if(mask % 2 == 0)
//                    suf += s[i];
//                else
//                    suf += s[i + 1];
//            } else {
//                suf += s[i + 2];
//                if(mask % 2 == 0)
//                    suf += min(s[i + 2], a[i]);
//                else
//                    suf += s[i + 2];
//            }

            int res = min({min(x, y), pref, suf});

//            cout << mask << ' ' << i << ' ' << res << ' ' << x << ' ' << y << ' ' << pref << ' ' << suf << endl;

            ans = max(ans, res);
        }

        if((mask == 3 || mask == 1) && nxt < k)
            a[b[nxt++].s] = mx;


//        if((mask == 3 || mask == 1) && k - 3 + __builtin_popcount(mask) >= 0)
//            a[b[k - __builtin_popcount(mask)].s] = mx;

    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}