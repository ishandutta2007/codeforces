#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

bool done[sz];
vector <int> g[sz];
int one;

void dfs(int u)
{
   done[u]=1;
   one++;
   for(int i=0; i<g[u].size(); i++) {
      int v=g[u][i];
      if(done[v]) continue;
      dfs(v);
   }
}

int main()
{
   int n,k;
   cin >> n >> k;
   for(int i=0; i<k; i++) {
      int x,y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }

   int ans=0;
   for(int i=1; i<=n; i++) {
      if(done[i]) continue;
      one=0;
      dfs(i);
      ans+=one-1;
   }

   cout << k-ans << endl;
}