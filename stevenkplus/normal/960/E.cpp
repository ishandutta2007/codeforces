#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
const int MOD = 1E9 + 7;
typedef pair<long long, long long> pii;
#define f first
#define s second

const pii ONE = pii(0, 1); // single-node path
pii operator+(pii a, pii b) {
  return pii(a.f + b.f, a.s + b.s);
}

pii operator*(pii a, pii b) {
  return pii(a.f * b.f + a.s * b.s, a.f * b.s + a.s * b.f);
}

pii operator-(pii a) {
  return pii(-a.f, -a.s);
}

pii operator~(pii a) {
  return pii(a.s, a.f);
}

pii operator-(pii a, pii b) {
  return a + -b;
}

pii operator%(pii a, long long b) {
  return pii(a.f % b, a.s % b);
}

long long A[MAXN];
vector<int> ed[MAXN];
pii down[MAXN]; // starting from here, going down, incl. self
pii up[MAXN]; // going out from parent, not incl. self
// up[n] = up[par[n]] + down[par[n]] - down[n]
// contribution of edge (par[n]--n): (up[n].odd * down[n].even - up[n].even * down[n].odd) * (val[par[n]] - val[n])
// even paths through n = down[n] * (1 + up[n])

void dfs1(int cur, int par) {
  vector<int> &e = ed[cur];
  pii &tot = down[cur];
  tot = tot + ONE;
  for (int i = 0; i < e.size(); ++i) {
    int nxt = e[i];
    if (nxt == par) continue;
    dfs1(nxt, cur);
    tot = tot + ~down[nxt];
  }
  tot = tot % MOD;
}

long long ans;
void dfs2(int cur, int par) {
  vector<int> &e = ed[cur];
  if (par) {
    up[cur] = ~up[par] + down[par] - ~down[cur];
    up[cur] = up[cur] % MOD;
    ans += ((up[cur].s + 1) * down[cur].f - up[cur].f * down[cur].s) * A[par];
    ans += (up[cur].s * (down[cur].f) - up[cur].f * (1 + down[cur].s)) * (-A[cur]);
    ans %= MOD;
  }
  for (int i = 0; i < e.size(); ++i) {
    int nxt = e[i];
    if (nxt == par) continue;
    dfs2(nxt, cur);
  }
}

int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  dfs1(1, 0);
  dfs2(1, 0);
  for(int i = 1; i <= n; ++i) {
    ans += A[i];
    ans %= MOD;
  }

  if (ans < 0) ans += MOD;
  cout << ans << "\n";
}