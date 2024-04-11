#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
const int IINF = 0x3f3f3f3f;
typedef pair<int, int> ipair;

vector<vector<int>> e1, e2;
vector<int> tin;
int ctin;
vector<int> d[2];
vector<ipair> ans;

int dfs1(int v, int pv) {
  tin[v] = ++ctin;
  int cur = tin[v];
  for (int nv : e1[v]) {
    if (nv == pv) continue;
    if (tin[nv] == -1) {
      int ncur = dfs1(nv, v);
      if (ncur >= tin[nv]) {
        e2[v].push_back(nv);
        e2[nv].push_back(v);
      }
      cur = min(cur, ncur);
    } else
      cur = min(cur, tin[nv]);
  }
  return cur;
}

void dfs2(int v, int pv) {
  tin[v] = 1;
  for (int &nv : e2[v]) {
    if (nv == pv) {
      nv = e2[v].back();
      e2[v].pop_back();
      break;
    }
  }
  for (int nv : e2[v]) dfs2(nv, v);
  if (e2[v].empty()) {
    d[0][v] = d[1][v] = 0;
    return;
  }

  for (int up = 0; up < 2; ++up) {
    if (pv == -1 && up) continue;
    int canEmp = pv == -1 || up;
    for (int emp = 0; emp <= canEmp; ++emp) {
      int rem = sz(e2[v]) - emp;
      int cd;
      if (rem % 2 == 0)
        cd = rem / 2;
      else if (up)
        cd = rem / 2;
      else
        cd = rem / 2 + 1;
      int v2 = -1;
      if (emp)
        for (int nv : e2[v])
          if (v2 == -1 || d[0][v2] - d[1][v2] > d[0][nv] - d[1][nv])
            v2 = nv;
      for (int nv : e2[v])
        cd += d[nv == v2 ? 0 : 1][nv];
      d[up][v] = min(d[up][v], cd);
    }
  }
}

void dfs3(int v, int* upv, bool root = true) {
  int up = upv != nullptr;

  if (e2[v].empty()) {
    if (up) {
      *upv = v;
    }
    return;
  }

  int canEmp = root || up;
  for (int emp = 0; emp <= canEmp; ++emp) {
    int rem = sz(e2[v]) - emp;
    int cd;
    if (rem % 2 == 0)
      cd = rem / 2;
    else if (up)
      cd = rem / 2;
    else
      cd = rem / 2 + 1;
    int v2 = -1;
    if (emp)
      for (int nv : e2[v])
        if (v2 == -1 || d[0][v2] - d[1][v2] > d[0][nv] - d[1][nv])
          v2 = nv;
    for (int nv : e2[v])
      cd += d[nv == v2 ? 0 : 1][nv];
    if (cd == d[up][v]) {
      vector<int> es;
      for (int nv : e2[v])
        if (nv != v2)
          es.push_back(nv);
      if (v2 != -1)
        dfs3(v2, nullptr, false);
      if (sz(es) % 2 == 1) {
        if (upv == nullptr) {
          ans.push_back({v, -1});
          upv = &ans.back().second;
        }
        dfs3(es.back(), upv, false);
        es.pop_back();
      } else if (upv != nullptr) {
        *upv = v;
      }
      for (int i = 0; i < sz(es); i += 2) {
        int u1 = es[i], u2 = es[i + 1];
        ans.push_back({-1, -1});
        int* upv1 = &ans.back().first;
        int* upv2 = &ans.back().second;
        dfs3(u1, upv1, false);
        dfs3(u2, upv2, false);
      }
      return;
    }
  }
  assert(false);
}

bool solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0) return false;
  e1.resize(n);
  e2.resize(n);
  for (int i = 0; i < m; ++i) {
    int len;
    cin >> len;
    int x = -1;
    for (int j = 0; j < len; ++j) {
      int y;
      cin >> y;
      --y;
      if (x != -1) {
        e1[x].push_back(y);
        e1[y].push_back(x);
      }
      x = y;
    }
  }

  ctin = 1;
  tin.resize(n, -1);
  dfs1(0, -1);

  fill(all(tin), 0);
  vector<int> roots;
  d[0].resize(n, IINF);
  d[1].resize(n, IINF);
  for (int i = 0; i < n; ++i) {
    if (tin[i]) continue;
    roots.push_back(i);
    dfs2(i, -1);
  }
  ans.reserve(n + 5);
  for (int i : roots) dfs3(i, nullptr);

  cout << sz(ans) << "\n";
  for (ipair const& p : ans) cout << p.first + 1 << " " << p.second + 1 << "\n";

  e1.clear();
  e2.clear();
  tin.clear();
  d[0].clear();
  d[1].clear();
  ans.clear();

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  while (solve());
}