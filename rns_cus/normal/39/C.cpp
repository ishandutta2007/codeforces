#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 2010

struct dist{
   int st;
   int en;
   int num;
}a[N];

int c, r, n, g[2*N][2*N];
long long pnt[2*N];
pair <int, int> p[N];

bool cmp(dist u, dist v){
   if(u.en != v.en) return u.en > v.en;
   return u.st <= v.st;
}

inline int f(long long x){
   return (x % (2 * N) + 2 * N) % (2 * N);
}

bool dfs(int st, int en){
   if(st >= en) return 1;
   if(g[st][en] == g[st+1][en]){ dfs(st + 1, en); return 1; }
   if(g[st][en] == g[st][en-1]){ dfs(st, en-1); return 1; }
   int cc = p[f(pnt[st])].second; int rr = p[2 * N - f(pnt[en])].first;
   if(1 + g[st+1][cc] + g[cc][en] > 1 + g[st][rr] + g[rr][en-1]){ printf("%d ", a[f(pnt[st])].num); dfs(st+1, cc); dfs(cc, en); return 1; }
   printf("%d ", a[2 * N - f(pnt[en])].num); dfs(st, rr); dfs(rr, en-1); return 1;
}

int main(){
   scanf("%d", &n);
   for(int i = 1; i <= n; i ++){
      scanf("%d %d", &c, &r);
      a[i].st = c - r; a[i].en = c + r; a[i].num = i;
   }
   sort(a + 1, a + n + 1, cmp);
   int cnt = 0;
   for(int i = 1; i <= n; i ++){
      pnt[cnt++] = 2ll * N * a[i].st + i;
      pnt[cnt++] = 2ll * N * a[i].en - i;
   }
   sort(pnt, pnt + cnt);
   for(int i = 0; i < cnt; i ++){
      c = (pnt[i] % (2 * N) + 2 * N) % (2 * N);
      if(c < N) p[c].first = i;
      else p[2 * N - c].second = i;
   }
   for(int d = 1; d < cnt; d ++){
      for(int i = 0; i + d < cnt; i ++){
         c = f(pnt[i]);
         r = 2 * N - f(pnt[i+d]);
         if(c > N or i + d < p[c].second){ g[i][i+d] = g[i+1][i+d]; continue; }
         if(r > N or i > p[r].first ){ g[i][i+d] = g[i][i+d-1]; continue; }
         g[i][i+d] = max(1 + g[i+1][p[c].second] + g[p[c].second][i+d], 1 + g[i][p[r].first] + g[p[r].first][i+d-1]);
         g[i][i+d] = max(g[i][i+d], max(g[i+1][i+d], g[i][i+d-1]));
      }
   }
   printf("%d\n", g[0][cnt-1]);
   dfs(0, cnt-1); puts("");
}