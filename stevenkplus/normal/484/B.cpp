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
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

// =========== Solution ============= //

const int MAXN = 1001000;
int fac[MAXN]; // fac[i]: largest factor of i in a_i, or 0 if none
int vis[MAXN];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vis[x] = 1;
  }

  for (int i = 1; i < MAXN; ++i) {
    if (!vis[i]) continue;
    for (int j = i; j < MAXN; j += i) {
      fac[j] = max(fac[j], i);
    }
  }

  PQ pq;
  int ans = 0;
  for (int i = 1; i < MAXN; ++i) {
    while (!pq.empty() && pq.top().se <= i) {
      pq.pop();
    }
    pq.push(pii(i, i + fac[i]));
    if (vis[i]) {
      int val = i - pq.top().fi;
      ans = max(ans, val);
    }
  }
  cout << ans << "\n";
}