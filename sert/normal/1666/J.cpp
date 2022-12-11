#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = static_cast<ll>(1e18) + 41;

void dfs(int l, int r, int pr, const vector<vector<int>> &bstTop, vector<int> &par) {
  int top = bstTop[l][r];
  par[top] = pr;
  if (l < top) {
    dfs(l, top - 1, top, bstTop, par);
  }
  if (top < r) {
    dfs(top + 1, r, top, bstTop, par);
  }
}

int main() {
#ifdef SERT
  freopen("../a.in", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<vector<ll>> c(n, vector<ll>(n));
  vector<vector<int>> bstTop(n, vector<int>(n, -1));
  vector<vector<ll>> bstCost(n, vector<ll>(n, INF));
  vector<vector<ll>> sumC(n + 1, vector<ll>(n + 1, 0));
  for (auto &row : c) {
    for (auto &x : row) {
      cin >> x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sumC[i][j] = sumC[i - 1][j] + sumC[i][j - 1] - sumC[i - 1][j - 1] + c[i - 1][j - 1];
    }
  }

  auto getSum = [&](int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return 0LL;
    return sumC[r1 + 1][r2 + 1] - sumC[r1 + 1][l2] - sumC[l1][r2 + 1] + sumC[l1][l2];
  };

  for (int i = 0; i < n; i++) {
    bstTop[i][i] = i;
    bstCost[i][i] = 0;
  }

  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      for (int top = l; top <= r; top++) {
        auto getCost = [&](int L, int R) -> ll {
          if (L > R) return 0LL;
          return getSum(L, R, 0, L - 1) + getSum(L, R, R + 1, n - 1) + bstCost[L][R];
        };
        ll cost = getCost(l, top - 1) + getCost(top + 1, r);

        //cout << l << " " << top << " " << r << " " << (l == top ? 9 : bstTop[l][top - 1]) << " " << (r == top ? 9 : bstTop[top + 1][r]) << " " << cost << endl;

        if (cost < bstCost[l][r]) {
          bstCost[l][r] = cost;
          bstTop[l][r] = top;
        }
      }
    }
  }

  //cout << bstCost[0][n - 1] << "\n";
  vector<int> par(n, -1);
  dfs(0, n - 1, -1, bstTop, par);
  for (int x : par) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}