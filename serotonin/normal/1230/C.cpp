#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

vector <int> g[10];
bool dice[7][7];
int ans=0, who[10];

void rec(int p, int n)
{
   if(p>n) {
      memset(dice, 0, sizeof(dice));
      for(int i=1; i<=n; i++) {
         for(int j=0; j<g[i].size(); j++) {
            int u=i, v=g[i][j];
            u=who[i], v=who[v];
            if(u>v) swap(u,v);
            dice[u][v]=1;
         }
      }
      int now=0;
      for(int i=1; i<7; i++) {
         for(int j=i; j<7; j++) {
            if(dice[i][j]) now++;
         }
      }
      ans=max(ans, now);
      return;
   }
   for(int i=0; i<7; i++) {
      who[p]=i;
      rec(p+1,n);
   }
}

int main()
{
   int n,m;
   cin >> n >> m;
   while(m--) {
      int x,y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }

   rec(1,n);

   printf("%d\n", ans);
}