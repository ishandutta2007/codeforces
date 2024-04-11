/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master"(it's going up every day xD ) :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll A[MAXN], B[MAXN];
ll n, T, a, b;

ll solve() {
    cin >> n >> T >> a >> b;
    ll ac = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x == 1) {
            bc++;
            A[i].Y = b;
        } else {
            ac++;
            A[i].Y = a;
        }
    }

    for (int i = 0; i < n; i++) cin >> A[i].X;
    sort(A, A + n);

    A[n].X = T + 1;
    A[n].Y = 0;

    ll ps = 0, ans = 0;

    for (int i = 0; i <= n; i++) {
//        debug(i)
        if (i > 0) {
            ps += A[i - 1].Y;
            if (A[i - 1].Y == a) ac--;
            else bc--;
        }
        ll rem = (A[i].X - 1) - ps;
        if (rem < 0) continue;
//        debug(rem)
        ll t_ans = i;
        ll a_earn = min(rem / a, ac);
        rem -= a_earn * a;
        ll b_earn = min(rem / b, bc);
        t_ans += a_earn + b_earn;
        ans = max(t_ans, ans);
//
//        debug(ps)
//        debug(ac)
//        debug(bc)
//        debug(a_earn)
//        debug(b_earn)
    }

    return cout << ans << endl, 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}