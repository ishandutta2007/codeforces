#include <bits/stdc++.h>
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
char a[1000][1000];
int was[1000][1000];

int calc(char c) {
  memset(was, 0, sizeof(was));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == c) {
        was[i][j]++;
        was[i + 1][j + 1]++;
        was[i + 1][j]--;
        was[i][j + 1]--;
      }
    }
  }  
  int cc = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (was[i][j] != 0) {
        cc++;
      }
    }
  }
  if (was[n][m] == 0) {
    cc++;
  }
  return cc;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  cout << min(calc('W'), calc('B')) << endl;
  return 0;
}