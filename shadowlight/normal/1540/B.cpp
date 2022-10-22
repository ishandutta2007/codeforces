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

int rev(int a) {
  return bp(a, mod - 2);
}


const int N = 207;

int dp[N][N];

void init() {
  for (int i = 0; i < N; ++i) {
    dp[0][i] = 1;
    dp[i][0] = 0;
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      add(dp[i][j], dp[i - 1][j]);
      add(dp[i][j], dp[i][j - 1]);
      dp[i][j] = mult(dp[i][j], rev(2));
    }
  }
}

vector <vector<int>> gr;


vector <int> blocked;
vector<int> path;

bool get_path(int v, int p, int t) {
  path.pb(v);
  if (v == t) {
    return true;
  }
  for (int u : gr[v]) {
    if (u == p) continue;
    if (get_path(u, v, t)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

vector<int> sz;
void dfs(int v, int p) {
  sz[v] = 1;
  for (int u : gr[v]) {
    if (u == p || blocked[u]) continue;
    dfs(u, v);
    sz[v] += sz[u];
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int n;
  cin >> n;

  gr.resize(n);
  blocked.resize(n);
  sz.resize(n);

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }

  int res = 0;
  int rn = rev(n);

  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < a; ++b) {
      
      int now = 0;

      path.clear();
      get_path(a, -1, b);

      blocked.assign(n, false);
      for (int v : path) {
        blocked[v] = true;
      }

      for (int v : path) {
        dfs(v, -1);
      }

      for (int i = 0; i < (int) path.size(); ++i) {
        int l = i, r = path.size() - 1 - i;
        int v = path[i];
        add(now, mult(sz[v], mult(rn, dp[l][r])));
        //cout << a << " " << b << " " << sz[v] << " " << rn << " " << dp[l][r] << endl;
      }
      add(res, now);
      //cout << a << " " << b << " " << now << endl;
    }
  }

  cout << res << "\n";
}