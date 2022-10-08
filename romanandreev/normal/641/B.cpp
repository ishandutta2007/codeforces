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

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);  
  vector<vector<int>> wh(n + 1, vector<int>(m + 1, 0));            
  vector<int> a(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      wh[i][j] = i * m + j;
    }
  }
  for (int it = 0; it < q; it++) {
    int t, x, y, z;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      x--;     
      wh[x][m] = wh[x][0];
      for (int i = 0; i < m; i++) {
        wh[x][i] = wh[x][i + 1];
      }      
    } else
    if (t == 2) {
      scanf("%d", &x);
      x--;     
      wh[n][x] = wh[0][x];
      for (int i = 0; i < n; i++) {
        wh[i][x] = wh[i + 1][x];
      }      
    } else {
      scanf("%d %d %d", &x, &y, &z);
      x--, y--;      
      a[wh[x][y]] = z;
    }       
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d%c", a[i * m + j], " \n"[j + 1 == m]);
    }
  }
  return 0;                              
}