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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    
    map<ll, ll> mp;
    vector<int> a;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (!mp[x]) {
        a.push_back(x);
      }
      mp[x]++;
    }

    vector<int> b;
    for (int x : a)
      b.push_back(mp[x]);
    
    sort(b.begin(), b.end());

    ll beegle = b.back() + 1, ans = 0;
    while (!b.empty()) {
      if (beegle == 0)
        break;
      
      if (beegle <= b.back()) {
        beegle--;
        ans += beegle;
      } else {
        ans += b.back();
        beegle = b.back();
      }
      b.pop_back();
    }

    cout << ans << endl;
  }
}