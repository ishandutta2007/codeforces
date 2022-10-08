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
const int maxn = (int)1e6;
int n;
vector<int> g[maxn];
int was[maxn];
vector<int> ls;
void dfs(int v, int h) {
  was[v] = 1;
  bool isls = true;
  for (auto e : g[v]) if (was[e] == 0) {
    isls = false;
    dfs(e, h + 1);
  }
  if (isls) {
    ls.pb(h);
  }
}
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  was[0] = 1;
  int Ans = 0;
  for (auto v : g[0]) {
    ls.clear();
    dfs(v, 0);
    sort(all(ls));  
    int ans = -1;
    for (auto x : ls) {
      ans = max(ans + 1, x);
    }
    Ans = max(ans + 1, Ans);
  }
  cout << Ans << endl;
  return 0;
}