#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 507;

int cnt[N][N];
int matrix[2 * N][N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      --x;

      matrix[i][j] = x;
      ++cnt[j][x];
    }
  }

  vector <int> res;
  int cnt_res = 1;
  vector <bool> ban(n, false);

  vector<bool> ban_row(2 * n, false);

  for (int iter = 0; iter < n; ++iter) {
    int ncol, nval;
    bool found = false;
    for (int col = 0; col < n; ++col) {
      if (ban[col]) continue;
      for (int val = 0; val < n; ++val) {
        if (cnt[col][val] > 0) {
          ncol = col, nval = val;
        }
        if (cnt[col][val] == 1) {
          found = true;
          break;
        }
      }
      if (found) break;
    }

    if (!found) {
      cnt_res = mult(cnt_res, 2);
    }

    int row = -1;
    for (row = 0; row < 2 * n; ++row) {
      if (ban_row[row]) continue;
      if (matrix[row][ncol] == nval) {
        break;
      }
    }

    res.pb(row);

    for (int nrow = 0; nrow < 2 * n; ++nrow) {
      if (ban_row[nrow]) continue;
      for (int col = 0; col < n; ++col) {
        if (matrix[row][col] == matrix[nrow][col]) {
          ban_row[nrow] = true;
          break;
        }
      }
      if (!ban_row[nrow]) continue;
      for (int col = 0; col < n; ++col) {
        --cnt[col][matrix[nrow][col]];
      }
    }
  }

  assert(res.size() == n);
  cout << cnt_res << "\n";
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}