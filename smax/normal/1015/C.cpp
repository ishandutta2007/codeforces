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

  int n, m;
  cin >> n >> m;
  vector<ll> v(n);
  ll sum = 0;
  for (int i=0; i<n; i++) {
    ll a, b;
    cin >> a >> b;
    sum += a;
    v[i] = a - b;
  }

  sort(v.begin(), v.end(), greater<ll>());
  ll diff = sum - m;
  if (diff <= 0) {
    cout << "0\n";
    return 0;
  }

  for (int i=0; i<n; i++) {
    diff -= v[i];
    if (diff <= 0) {
      cout << i + 1 << "\n";
      return 0;
    }
  }

  cout << "-1\n";

  /*ll n;

  string s, t;

  cin >> n >> s >> t;

  string a, b;
  a = s; b = t;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());


  if (a != b) {
    cout << -1 << endl;
    return 0;
  }

  map<char, set<char> > m;

  f0r(i, t.size()) {
    f0r(j, i) {
      m[t[i]].insert(t[j]);
    }
  }

  vector<ll> v;

  while (s != t) {
    f0r(i, s.size() - 1) {
      char c = s[i];
      if (m[c].count(s[i + 1])) {
        swap(s[i], s[i + 1]);
        v.pb(i + 1);
      }
    }
  }

  cout << v.size() << endl;
  ao(v, v.size());*/
}