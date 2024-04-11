#include<bits/stdc++.h>
using namespace std;
#define N 300010
int n, m, k, x, y;
set <int> S, v[N];
bool vis[N];

void dfs(int x){
   if(vis[x]) return; vis[x] = 1;
   S.erase(S.find(x));
   if(S.empty()) return;
   int cnt = 0, cur = 0;
   while(cnt < k or x != 1){
      set<int>::iterator it = S.lower_bound(cur + 1);
      if(it == S.end()) break;
      cur = *it;
      if(v[x].find(cur) != v[x].end()) continue;
      dfs(cur);
      cnt ++;
   }
}

int main(){
   ios::sync_with_stdio();
   cin >> n >> m >> k;
   for(int i = 0; i < m; i ++){
      cin >> x >> y;
      v[x].insert(y);
      v[y].insert(x);
   }
   if(n - v[1].size() - 1 < k){puts("impossible"); return 0; }
   for(int i = 1; i <= n; i ++) S.insert(i);
   dfs(1);
   if(S.empty()){ puts("possible"); return 0;}
   puts("impossible"); return 0;
}