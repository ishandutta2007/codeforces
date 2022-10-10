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

bool prime[3000000];
map<ll, ll> mp;
ll cnt = 1;

void sieve() {
  f0r(i, 3000000) {
    prime[i] = true;
  }
  prime[0] = prime[1] = false;
  for (ll i = 2; i < 3000000; i++) {
    if (prime[i]) {
      mp[i] = cnt;
      cnt++;
      for (ll j = i * i; j < 3000000; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  sieve();

  ll n;
  cin >> n;

  ll b[2 * n];
  map<ll, ll> m;

  f0r(i, 2 * n) {
    cin >> b[i];
    m[b[i]]++;
  }

  sort(b, b + 2 * n);

  vector<ll> ans;

  for (ll i = 2 * n - 1; i >= 0; i--) {
    if (m[b[i]] == 0) {
      continue;
    }
    if (prime[b[i]]) {
      ans.pb(mp[b[i]]);
      m[mp[b[i]]]--;
    } else {
      bool beegle = false;
      for (ll j = 2; j * j <= b[i]; j++) {
        if (b[i] % j == 0) {
          ans.pb(b[i]);
          m[b[i]/j]--;
          beegle = true;
          break;
        }
      }
      
      if (!beegle) {
        ans.pb(b[i]);
        m[1]--;
      }
    }
  m[b[i]]--;
  }

  assert(ans.size() == n);
  ao(ans, ans.size());


}