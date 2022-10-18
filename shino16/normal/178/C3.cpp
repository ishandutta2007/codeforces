#line 1 "main.cpp"
// https://codeforces.com/contest/178/submission/15774685
//God & me
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define hash kjsdf
//#define int long long
using namespace std;
typedef pair<int, int> pii;

const int maxn = 2e5 + 17;
int n, m, gp[maxn], rate[maxn], cnt, sz[maxn];
unordered_map<int, pii> p;
set<int> s[maxn];
vector<int> ag[maxn];
void dfs(int v, int rt = 0) {
  if (gp[v]) return;
  gp[v] = cnt, rate[v] = rt;
  s[cnt].insert(rt);
  sz[cnt]++;
  dfs((v + m) % n, rt + 1);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    if (!gp[i]) cnt++, dfs(i);
  int q;
  cin >> q;
  for (int id, h; q--;) {
    char c;
    cin >> c >> id;
    if (c == '+') {
      cin >> h;
      int g = gp[h], r = rate[h];
      auto it = s[g].lower_bound(r);
      if (it == s[g].end()) it = s[g].begin(), ans += sz[g];
      ans += *it - r;
      p[id] = {g, *it};
      s[g].erase(it);
    } else {
      auto tmp = p[id];
      s[tmp.X].insert(tmp.Y);
    }
  }
  cout << ans << '\n';
  return 0;
}