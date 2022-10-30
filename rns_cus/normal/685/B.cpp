#include<bits/stdc++.h>
using namespace std;

#define N 300030

vector <int> v[N];
int gas[N], vis[N], des[N], ctr[N], a[N];

void dfs(int x){
   gas[x] = 1;
   for(int i = 0; i < v[x].size(); i ++){
      dfs(v[x][i]);
      gas[x] += gas[v[x][i]];
   }
   for(int i = 0; i < v[x].size(); i ++){
      if(gas[v[x][i]] > (gas[x] >> 1) ) des[x] = v[x][i];
   }
}

void calc(int x){
   int cnt = 1;
   int st, en, mid;
   int cur = x; a[0] = cur; vis[cur] = 1;
   while(des[cur]){
      cur = des[cur];
      a[cnt ++] = cur;
      vis[cur] = 1;
   }
   for(int j = 0; j < cnt; j ++){
      st = j;
      en = cnt;
      while(st < en - 1){
         mid = (st + en) / 2;
         if(gas[a[mid]] > gas[a[j]] / 2) st = mid;
         else en = mid;
      }
      ctr[a[j]] = a[st];
   }
   //printf("%d\n", cnt);
   //printf("%d %d\n", x, des[x]);
}

int main(){
   //freopen("b.in", "r", stdin);
   int n, m, x;
   scanf("%d %d", &n, &m);
   for(int i = 2; i <= n; i ++){
      scanf("%d", &x);
      v[x].push_back(i);
   }
   dfs(1);
   for(int i = 1; i <= n; i ++)if(!vis[i]) {
      calc(i);
   }
   while(m -- ){
      scanf("%d", &x);
      printf("%d\n", ctr[x]);
   }
}