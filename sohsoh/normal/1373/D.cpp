/*
    Soheil Mohammadkhani
    finally, i've got candidate master, so wait for the text :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10; // Change this  :|
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n, sum = 0, ps2[MAXN], ps1[MAXN];

ll solve1() {
    ll mp = 0, res = -INF;
    for (int i = 0; i < n; i++) {
        res = max(res, ps1[i] - mp);
        mp = min(mp, ps1[i]);
    }

    return res;
}

ll solve2() {
    ll mp = 0, res = -INF;
    for (int i = 0; i < n; i++) {
        res = max(res, ps2[i] - mp);
        mp = min(mp, ps2[i]);
    }

    return res;
}

ll solve() {
    cin >> n;
    fill(ps1, ps1 + n, 0);
    fill(ps2, ps2 + n, 0);
    sum = 0;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += A[i];
            if (i > 0) ps1[i / 2] = A[i - 1] - A[i];
            if (i + 1 < n) ps2[i / 2] = A[i + 1] - A[i];
        }
    }

    for (int i = 1; i < n; i++) {
        ps1[i] += ps1[i - 1];
        ps2[i] += ps2[i - 1];
    }

    ll ans = sum;
    ans = max(ans, sum + solve1());
    ans = max(ans, sum + solve2());
    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
            solve();
    }
    return 0;
}