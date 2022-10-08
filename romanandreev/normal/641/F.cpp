#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int maxn = 2016;
vector<int> g[2][maxn];
vector<int> g2[2][maxn];
vector<int> gr[2][maxn];
int n;
int neg(int x) {
  if (x < n) {
    return x + n;
  } else {
    return x - n;
  }
}
void add(int f, int x, int y) {
  g[f][x].pb(y);
  gr[f][y].pb(x);
}
vector<int> was;
vector<int> ls[2];
vector<int> col[2];
vector<int> who[2][maxn];
int C[2];
void dfs1(int f, int v) {
  was[v] = 1;
  for (int e : g[f][v]) if (!was[e]) {
    dfs1(f, e);
  }
  ls[f].pb(v);
}
void dfs2(int f, int v, int c) {
  col[f][v] = c;
  who[f][c].pb(v);
  for (int e : gr[f][v]) if (col[f][e] == -1) {
    dfs2(f, e, c);
  }
}
void compress(int f) {
  was = vector<int>(2 * n, 0);
  for (int i = 0; i < 2 * n; i++) {
    if (was[i] == 0) {
      dfs1(f, i);
    }
  }
  col[f] = vector<int>(2 * n, -1);
  reverse(all(ls[f]));
  C[f] = 0;
  for (int v : ls[f]) {
    if (col[f][v] == -1) {
      dfs2(f, v, ++C[f]);
    }
  }
  for (int v = 0; v < 2 * n; v++) {
    for (int e : g[f][v]) {
      g2[f][col[f][v]].pb(col[f][e]);
    }
  }
  for (int i = 1; i <= C[f]; i++) {
    image(g2[f][i]);
  }
}
vector<ull> path[2][maxn];
int K;
void SET(vector<ull>& a, int x) {
  a[x >> 6] |= ((ull)1) << (x & 63);
}
bool ISONE(vector<ull>& a, int x) {
  return (a[x >> 6] >> (x & 63)) & 1;
}
void OR(vector<ull>& a, vector<ull>& b, int x) {
  for (int i = x >> 6; i < K; i++) {
    a[i] |= b[i];
  }
}
void calcpath(int f) {
  K = (C[f] + 1) / 64 + 2;
  for (int i = 1; i <= C[f]; i++) {
    path[f][i] = vector<ull>(K, 0);
  }
  for (int v = C[f]; v >= 1; v--) {
    SET(path[f][v], v);
    for (int e : g2[f][v]) {
      OR(path[f][v], path[f][e], e);
    }
  }  
}
void printsol(int f) {
  for (int i = 0; i < n; i++) {
    if (col[f][i] < col[f][i + n]) {
      printf("0 ");
    } else {
      printf("1 ");
    }
  }
}
vector<pair<int, int>> lse[2];
bool can1(int f, int x) {
//  cerr<<f<<" "<<x<<" "<<col[f][x]<<" "<<path[f][col[f][x]][0]<<endl;
  return !ISONE(path[f][col[f][x]], col[f][neg(x)]); 
}
bool can2(int f, int x1, int x2) {
  for (int i = 0; i < n; i++) {
    int val1 = -1;
    if (ISONE(path[f][col[f][x1]], col[f][i])) {
      val1 = 1;
    }
    if (ISONE(path[f][col[f][x1]], col[f][i + n])) {
      val1 = 0;
    }
    int val2 = -1;
    if (ISONE(path[f][col[f][x2]], col[f][i])) {
      val2 = 1;
    }
    if (ISONE(path[f][col[f][x2]], col[f][i + n])) {
      val2 = 0;
    }
    if (val1 != -1 && val2 != -1) {
      if (val1 != val2) {
        return false;
      }
    }
  }
  return true;
}
bool canprint(int f, int x1, int x2) {
  for (int i = 0; i < n; i++) {
    int val1 = -1;
    if (ISONE(path[f][col[f][x1]], col[f][i])) {
      val1 = 1;
    }    
    if (ISONE(path[f][col[f][x1]], col[f][i + n])) {
      val1 = 0;
    }
    int val2 = -1;
    if (ISONE(path[f][col[f][x2]], col[f][i])) {
      val2 = 1;
    }
    if (ISONE(path[f][col[f][x2]], col[f][i + n])) {
      val2 = 0;
    }
    if (val1 == -1) {
      if (val2 == -1) {
        if (col[f][i] < col[f][i + n]) {
          printf("0 ");
        } else {
          printf("1 ");
        }
      } else {
        printf("%d ", val2);
      }
      continue;
    }
    if (val2 == -1) {
      if (val1 == -1) {
        if (col[f][i] < col[f][i + n]) {
          printf("0 ");
        } else {
          printf("1 ");
        }
      } else {
        printf("%d ", val1);
      }
      continue;
    }    
    printf("%d ", val1);    
  }
  return false;
}
void can(int f1, int f2) {
  for (auto p : lse[f1]) {
    int v1 = p.x;
    int v2 = p.y;
    if (can1(f2, neg(v1)) && can1(f2, neg(v1))) {           
      if (can2(f2, neg(v1), neg(v2))) {
        canprint(f2, neg(v1), neg(v2));
        exit(0);
      }
    }
  }  
}
int main(){
  #ifdef home
  assert(freopen("1.out","wt",stdout));
  assert(freopen("1.in","rt",stdin));
  #endif              
  vector<int> m(2, 0);
  scanf("%d %d %d", &n, &m[0], &m[1]);
  for (int f = 0; f < 2; f++) {
    for (int i = 0; i < m[f]; i++) {
      int x, y;
      scanf("%d %d", &x, &y);      
      if (x > 0) {
        x = x - 1;
      } else {
        x = -x - 1 + n;
      }
      if (y > 0) {
        y = y - 1;
      } else {
        y = -y - 1 + n;
      }
      lse[f].pb(mp(x, y));
      add(f, neg(x), y);
      add(f, neg(y), x);
    }    
    compress(f);    
    calcpath(f);
  }
  vector<bool> nosol(2 , false);
  for (int f = 0; f < 2; f++) {
    for (int i = 0; i < n; i++) {
      if (ISONE(path[f][col[f][i]], col[f][i + n]) && ISONE(path[f][col[f][i + n]], col[f][i])) {
        nosol[f] = true;
      }
    }
  }
  if (nosol[0] && nosol[1]) {
    printf("SIMILAR\n");
    return 0;
  }
  if (nosol[0] && !nosol[1]) {
    printsol(1);
    return 0;
  }
  if (!nosol[0] && nosol[1]) {
    printsol(0);
    return 0;
  }
  can(0, 1);
  can(1, 0);
  printf("SIMILAR\n");
  return 0;
}