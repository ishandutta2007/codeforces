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

const int MAXN = 100100;
int n, m;
int D[MAXN]; // D[i] -- 0 or id of exam
int A[MAXN]; // A[i] study cost of exam i (1-indexed)

bool can(int days) {
  vector<pii> v(m);
  for (int i = 0; i < days; ++i) {
    int e = D[i];
    if (!e) continue;
    v[e - 1] = pii(i, e);
  }
  sort(v.begin(), v.end());
  int cost = 0;
  for (auto p: v) {
    if (!p.se) return false;
    if (cost + A[p.se] > p.fi) return false;
    cost += A[p.se] + 1;
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> D[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> A[i];
  }
  if (!can(n)) {
    cout << "-1\n";
    return 0;
  }
  int lo = 0;
  int hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (can(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << hi << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases