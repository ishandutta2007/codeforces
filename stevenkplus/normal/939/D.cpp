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

class DSU {
  vector<int> par;
  public:
    DSU(int size) {
      par = vector<int>(size);
      for (int i = 0; i < size; ++i) {
        par[i] = i;
      }
    }

    int find(int x) {
      if (par[x] == x) return x;
      return par[x] = find(par[x]);
    }

    // set a to point to b
    bool join(int a, int b) {
      a = find(a);
      b = find(b);
      if (a != b) {
        par[a] = b;
        return true;
      }
      return false;
    }
};

// =========== Solution ============= //

int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<pii> ans;
  DSU dsu(1000);
  for (int i = 0; i < n; ++i) {
    int c1 = a[i], c2 = b[i];
    if (dsu.find(c1) != dsu.find(c2)) {
      c1 = dsu.find(c1);
      c2 = dsu.find(c2);
      dsu.join(c1, c2);
      ans.push_back(pii(c1, c2));
    }
  }
  cout << ans.size() << "\n";
  for (pii p: ans) {
    cout << char(p.fi) << " " << char(p.se) << '\n';
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]