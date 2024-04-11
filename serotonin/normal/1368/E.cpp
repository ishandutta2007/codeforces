#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int, int> pii;
#define x first
#define y second

int done[sz];
vector <int> g[sz];

void solve()
{
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) done[i] = 2, g[i].clear();
   while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
   }

   vector <int> ans;
   for(int i=1; i<=n; i++) {
      if(!done[i]) ans.push_back(i);
      else for(int j : g[i]) done[j] = min(done[i] -1, done[j]);
   }

   printf("%d\n", ans.size());
   for(int i : ans) printf("%d ", i);
   puts("");
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}