#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

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

void solve() {
  multiset <pair<int, int>> q;

  int n, m;
  cin >> n >> m;

  vector <vector <int>> a(n);
  vector <int> ban(n, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      a[i].pb(x);
      q.insert({x, i});
    }
    sort(all(a[i]));
  }
  vector <vector<int>> res(n, vector<int>(m));
  for (int i = 0; i < m; ++i) {
    auto d = *q.begin();
    q.erase(q.begin());
    res[d.y][i] = d.x;
    ++ban[d.y];

    for (int j = 0; j < n; ++j) {
      if (d.y == j) {
        continue;
      }
      int val = a[j][(m - 1) - i + ban[j]];
      res[j][i] = val;
      //cout << a[j][(m - 1) - i + ban[j]] << " ";
      q.erase(q.find({val, j}));
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}