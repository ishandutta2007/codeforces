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
//#define SZ(x)                       ll(x.size());
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

ll maxSubArraySum(ll a[], ll SZ)
{
   ll max_so_far = 0, max_ending_here = 0;
   for (ll i = 0; i < SZ; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main() {
    fast_io;
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        ll* a = new ll[n - 1];
        ll* a2 = new ll[n - 1];
        ll s = 0;
        for (int i = 0; i < n; i++) {
            ll k;
            cin >> k;
            s += k;

            if (i > 0) a2[i - 1] = k;
            if (i < n - 1) a[i] = k;
        }

        ll s1 = maxSubArraySum(a2, n - 1);
        ll s2 = maxSubArraySum(a, n - 1);
        if (s > s1  && s > s2) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}