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

vector <vector<int>> gr;
vector <vector<int>> rgr;

const int D = 4;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

vector <string> field;


vector <int> order;
vector<bool> used;
void dfs(int v) {
  if (used[v]) return;
  used[v] = true;
  for (int u : gr[v]) {
    dfs(u);
  }
  order.pb(v);
}

vector<int> col;
int now = 0;

void rdfs(int v) {
  if (col[v]) return;
  col[v] = now;
  for (int u : rgr[v]) {
    rdfs(u);    
  }
}

int m;

void condense(vector<vector<int>>& gr) {
  int n = gr.size();
  
  order.clear();
  used.assign(n, false);

  for (int i = 0; i < n; ++i) {
    int x = i / m, y = i % m;
    if (field[x][y] != '#') continue;
    dfs(i);
  }
  reverse(all(order));
  rgr.assign(n, {});
  for (int i = 0; i < n; ++i) {
    for (int v : gr[i]) {
      rgr[v].pb(i);
    }
  }

  col.assign(n, 0);
  now = 0;
  for (int x : order) {
    if (col[x]) continue;
    ++now;
    rdfs(x);
  }
  //cout << now << endl;

  vector<vector<int>> grn(now);
  for (int v = 0; v < n; ++v) {
    //cout << v / m << " " << v % m << " " << col[v] << endl;
    for (int u : gr[v]) {
      if (col[v] != col[u]) {
        grn[col[v] - 1].pb(col[u] - 1);
      }
    }
  }
  gr = grn;
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n >> m;
  field.resize(n);
  gr.resize(n * m);

  vector <vector<int>> cols(m);

  for (int i = 0; i < n; ++i) {
    cin >> field[i];
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '#') {
        cols[j].pb(i);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] != '#') continue;
      int v = i * m + j;
      for (int d = 0; d < D; ++d) {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x < 0 || x >= n || y < 0 || y >= m || field[x][y] != '#') continue;
        gr[v].pb(x * m + y);
      }
      
      if (j > 0) {
        int pos = upper_bound(all(cols[j - 1]), i) - cols[j - 1].begin();
        if (pos != cols[j - 1].size()) {
          gr[v].pb(cols[j - 1][pos] * m + (j - 1));
        }
      }

      if (j < m - 1) {
        int pos = upper_bound(all(cols[j + 1]), i) - cols[j + 1].begin();
        if (pos != cols[j + 1].size()) {
          gr[v].pb(cols[j + 1][pos] * m + (j + 1));
        }
      }
      int pos = upper_bound(all(cols[j]), i) - cols[j].begin();
      if (pos != cols[j].size()) {
        gr[v].pb(cols[j][pos] * m + j);
      }
    }
  }

  condense(gr);

  int N = gr.size();

  vector <int> rdeg(N, 0);

  for (int v = 0; v < N; ++v) {
    for (int u : gr[v]) {
      rdeg[u]++;
    }
  }
  int cnt = 0;
  for (int v = 0; v < N; ++v) {
    cnt += !rdeg[v];
  }
  cout << cnt << "\n";
}