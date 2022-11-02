#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector <int> v[N], ans[4];
bool sign[N], vis[N];
queue <int> Q;
int n, m, cur, pos, x, y;

bool bfs(int x){
   while(!Q.empty()) Q.pop();
   Q.push(x); vis[x] = 1;
   while(!Q.empty()){
      cur = Q.front(); Q.pop();
      for(int j = 0; j < v[cur].size(); j ++){
         pos = v[cur][j];
         if(vis[pos]){
            if(sign[pos] == sign[cur]) return 1;
            continue;
         }
         sign[pos] = 1 - sign[cur];
         Q.push(pos);
         vis[pos] = 1;
      }
   }
   return 0;
}

int main(){
  // freopen("a.in", "r", stdin);

   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; i ++) v[i].clear();
   for(int i = 0; i < m; i ++){
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
   }
   for(int i = 1; i <= n; i ++){
      if(vis[i]) continue;
      if(bfs(i)){ puts("-1"); return 0; }
   }
   ans[0].clear();
   ans[1].clear();
   for(int i = 1; i <= n; i ++){
      if(!v[i].size()) continue;
      if(sign[i]) ans[1].push_back(i);
      else ans[0].push_back(i);
   }

   printf("%d\n", ans[0].size());
   for(int i = 0; i < ans[0].size(); i ++) printf("%d ", ans[0][i]); puts("");
   printf("%d\n", ans[1].size());
   for(int i = 0; i < ans[1].size(); i ++) printf("%d ", ans[1][i]); puts("");
}