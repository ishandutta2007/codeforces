#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n, m;
char s[2010][2010];
const int MX = 2010 * 2010;
queue<int> S;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
int cnt[MX];

void del(int v) {
  for (int k = 0; k < 4; k++) {
    int i1 = v / m + dx[k];
    int j1 = v % m + dy[k];
    if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && s[i1][j1] == '.') {
      int e = i1 * m + j1;
      cnt[e]--;
      cnt[v]--;
      if (cnt[e] == 1) {
        S.push(e);
      }
    }
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (s[i][j] == '.') {      
      cc++;
      for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && s[i1][j1] == '.') {
          cnt[i * m + j]++;
        }
      }
      if (cnt[i * m + j] == 1) {
        S.push(i * m + j);
      }
    }  
  }

  while (sz(S) > 0) {
    int t = S.front();
    S.pop();
    if (cnt[t] != 1) {
      continue;
    }
    int v1 = t;
    int v2 = -1;
    for (int k = 0; k < 4; k++) {
      int i1 = v1 / m + dx[k];
      int j1 = v1 % m + dy[k];
      if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && s[i1][j1] == '.') {
        v2 = i1 * m + j1;
      }
    }
    if (v1 > v2) {
      swap(v1, v2);
    }
    if (v1 / m == v2 / m) {
      s[v1 / m][v1 % m] = '<';
      s[v2 / m][v2 % m] = '>';
    } else {
      s[v1 / m][v1 % m] = '^';
      s[v2 / m][v2 % m] = 'v';
    }
    del(v1);
    del(v2);
    cc -= 2;
    cnt[v1] = 0;
    cnt[v2] = 0;
  }
  if (cc != 0) {
    printf("Not unique\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", s[i]);
  }
  return 0;
}