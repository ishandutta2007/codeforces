#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int maxn = 151000;
int was[maxn];
vector<int> g[maxn];
int cnt1, cnt2;
void dfs(int v) {
  was[v] = 1;
  cnt1++;
  cnt2 += sz(g[v]);
  for (int e : g[v]) if (was[e] == 0) {
    dfs(e);
  }
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }  
  for (int i = 0; i < n; i++) if (was[i] == 0) {
    cnt1 = 0;
    cnt2 = 0;
    dfs(i);
    if ((ll)cnt1 * (cnt1 - 1) != cnt2) {
      printf("NO\n");
      return;
    }
  } 
  printf("YES\n");
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}