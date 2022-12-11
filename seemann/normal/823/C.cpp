#include <bits/stdc++.h>

using namespace std;

#define forn(a, b) for (int a = 0; (a) < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const ldb EPS = 1e-8;
const int MAXN = 1e5+100;
const int K = 1e5;

int main() {
#ifdef LOCAL
        freopen("c.in", "r", stdin);
        //freopen("", "w", stdout);
#endif
        int n;
        ll b;
        cin.sync_with_stdio(false);
        cin >> n >> b;
        vector<ll> a;
        forn(i, n) {
                int x;
                cin >> x;
                a.push_back(x);
        }
        ll ans = 1;

        ll sum = 0;
        for (int d = 2; d <= K; ++d) {
                sum = 0;
                forn(i, n) {
                        sum += (a[i] + d - 1) / d * d - a[i];
                }
                if (sum <= b) {
                        ans = d;
                }
        }
        vector<pair<ll, int>> e;
        forn(i, n) {
                ll pr = K;
                while (true) {
                    ll k = (a[i] + pr - 1) / pr;
             //       cerr << "ST " << pr << ' ' << k << '\n';
                    if (k <= 1)
                            break;
                    ll nxt = a[i] / (k - 1);
                    bool good = false;
                    for (ll c = nxt - 2; c <= nxt + 2; ++c) {
                        if ((a[i] + c - 1) / c < k) {
                                nxt = c;
                                good = true;
                            //    cerr << c << '\n';
                            //    cerr << k << ' ' << (a[i] + c - 1) / c << '\n';
                                break;
                        }
                    }
                    assert(good);
               //     cerr << nxt << '\n';
                    e.push_back({nxt, i});
                    pr = nxt;
                }
        }
        sort(e.begin(), e.end());
        ll sumq = 0;
        forn(i, n) {
                sumq += (a[i] + K - 1) / K;
        }
        //cerr << K << ' ' << sumq << '\n';
        forn(i, n) {
                b += a[i];
        }
        ll pr = K;
        vector<ll> prev(n, K);
        for (auto p : e) {
                //cerr << p.first << ' ' << p.second << '\n';
                //cerr << pr << ' ' << sumq << '\n';
                ll cd = p.first;
                ll h = b / sumq;
                if (h >= pr)
                    ans = max(ans, h);
                int i = p.second;
                sumq += (a[i] + cd - 1) / cd-(a[i] + prev[i] - 1) / prev[i];
                prev[i] = cd;
                pr = cd;
        }
        ll h = b / sumq;
        if (h >= pr)
            ans = max(ans, h);
        cout << ans << '\n';
        return 0;
}