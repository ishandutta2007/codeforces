// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

// =========== Solution ============= //


int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  PQ pq;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    pq.push(pll(v[i], i));
  }
  while (!pq.empty()) {
    while (!pq.empty() && v[pq.top().se] != pq.top().fi) pq.pop();
    pll a = pq.top();
    pq.pop();
    while (!pq.empty() && v[pq.top().se] != pq.top().fi) pq.pop();
    if (!pq.empty()) {
      pll b = pq.top();
      if (a.fi == b.fi) {
        v[a.se] = 0;
        v[b.se] *= 2;
        pq.pop();
        pq.push(pll(v[b.se], b.se));
      }
    }
  }

  int ans = 0;
  for(ll i: v) {
    if (i) ++ans;
  }
  cout << ans << "\n";

  for(ll i: v) {
    if (i) cout << i << ' ';
  }
  cout << "\n";
}