#include <bits/stdc++.h>
 
using namespace std;
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second
 
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
 
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
const ll inf = 1e12;
const ll mod = 1e9 + 7;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  ll t, n, a;
  cin >> t;

  f0r(x, t) {
    cin >> n;
    vector<ll> v(3);
    f0r(i, n) {
      cin >> a;
      v[a % 3]++;
    }
    ll beegle = min(v[1], v[2]);
    v[1] -= beegle;
    v[2] -= beegle;

    cout << beegle + v[0] + v[1]/3  + v[2]/3 << endl;
  }
}