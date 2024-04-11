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
  for (int i=0; i<n; i++) {
    long long x;
    cin >> x;

    if (x == 1) {
      cout << "0" << endl;
      continue;
    }

    vector<long long> a(3);
    while (x % 2 == 0) {
      a[0]++;
      x /= 2;
    }
    while (x % 3 == 0) {
      a[1]++;
      x /= 3;
    }
    while (x % 5 == 0) {
      a[2]++;
      x /= 5;
    }
    if (x != 1) {
      cout << "-1" << endl;
      continue;
    }
    cout << a[0] + 2 * a[1] + 3 * a[2] << endl;
  }
}