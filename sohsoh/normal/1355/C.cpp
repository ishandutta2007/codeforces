/*
    Soheil Mohammadkhani
    hello friend :)
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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN] = {0};
ll A, B, C, D;

//Finally Solved :)

ll p_diff(ll x) {
    ll ub = min(C + x, D);
    ll lb_tmp = max(C - x, B);
    ll lb = lb_tmp + x;
    if (ub - lb + 1 > 0) return ub - lb + 1;
    return 0;
}

int main() {
    fast_io;
    cin >> A >> B >> C >> D;

    cnt[0] = 1;
    for (int i = 1; i <= B + 2; i++) {
        cnt[i] = cnt[i - 1] + p_diff(i);
    }

    ll ans = 0;
    for (int i = A; i <= B; i++) {
        ans += cnt[i - 1];
    }

    cout << ans << endl;
    return 0;
}