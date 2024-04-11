/*
    Soheil Mohammadkhani
    IDK :)
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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int solve() {
    ll a, b, q;
    cin >> a >> b >> q;
    ll lcm = a * b / __gcd(a, b);
    ll ter = 0;
    ll arr[lcm + 1];
    ll* sum = arr + 1;
    fill(sum - 1, sum + lcm, 0);
    for (int i = 0; i < lcm; i++) {
        if ((i % a) % b != (i % b) % a) ter++;
        sum[i] = ter;
    }

//    alog(we_now, re);
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll res = 0;

        if (l / lcm == r / lcm) { cout << sum[r % lcm] - sum[l % lcm - 1] << " ", 0; continue;}

        res -= sum[l % lcm - 1];
        l -= l % lcm;
        res += ((r / lcm) - (l / lcm)) * ter;
        res += sum[r % lcm];
        cout << res << " ";
    }
    cout << endl;
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