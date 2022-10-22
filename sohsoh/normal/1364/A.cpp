/*
    Soheil Mohammadkhani
    Maybe candidate after this contest :)
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

const ll MAXN = 1e6 + 10; //Change me please :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0};

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, s = 0, smallest = INF;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            s += A[i];
        }

        ll l = n;
        if (s % x == 0) {
            ll l1 = l, l2 = l;
            for (int i = 0; i < n; i++) {
                l1--;
                if (A[i] % x) break;
            }

            for (int i = n - 1; i >= 0; i--) {
                l2--;
                if (A[i] % x) break;
            }

            ll ans = max(l1, l2);
            if (ans == 0) ans = -1;
            cout << ans << endl;
        } else cout << n << endl;
    }
    return 0;
}