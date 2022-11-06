#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
template<class A, class B>
void chkmin(A& a, const B& b) {
  if (b < a) {
    a = b;
  }
}
template<class A, class B>
void chkmax(A& a, const B& b) {
  if (b > a) {
    a = b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mn = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      chkmin(mn, a[i]);
    }
    vector<int> p;
    vector<ll> b;
    for (int i = 0; i < n; ++i) {
      if (a[i] % mn == 0) {
        p.pb(i);
        b.pb(a[i]);
      }
    }
    sort(all(b));
    for (int i = 0; i < sz(p); ++i) a[p[i]] = b[i];
    cout << (is_sorted(all(a)) ? "YES\n" : "NO\n");
  }
  return 0;
}