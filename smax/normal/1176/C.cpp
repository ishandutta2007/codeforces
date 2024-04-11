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
  
  int n;
  cin >> n;
  vector<int> v(6);
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    if (x == 4) v[0]++;
    else if (x == 8) v[1] = min(v[0], v[1] + 1);
    else if (x == 15) v[2] = min(v[1], v[2] + 1);
    else if (x == 16) v[3] = min(v[2], v[3] + 1);
    else if (x == 23) v[4] = min(v[3], v[4] + 1);
    else if (x == 42) v[5] = min(v[4], v[5] + 1);
  }

  cout << n - 6 * v[5] << endl;
}