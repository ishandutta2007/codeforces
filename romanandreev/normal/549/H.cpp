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
const ld eps = 1e-9;
ld a, b, c, d;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};
bool can2(ld x1, ld y1, ld D) {
  bool zn1 = false;
  bool zn2 = false;
  for (int i = 0; i < 4; i++) {  
    ld x2 = c + dx[i] * D;
    ld y2 = d + dy[i] * D;    
    if (x1 * y2 - x2 * y1 < 0) zn1 = true; 
    else zn2 = true;
  }
  return zn1 && zn2;
}
bool can3(ld x1, ld y1, ld D) {
  bool zn1 = false;
  bool zn2 = false;
  for (int i = 0; i < 4; i++) {  
    ld x2 = a + dx[i] * D;
    ld y2 = b + dy[i] * D;    
    if (x1 * y2 - x2 * y1 < 0) zn1 = true; 
    else zn2 = true;
  }
  return zn1 && zn2;
}
bool can(ld D) {
  if (max(fabs(a), fabs(b)) <= D) return true;
  if (max(fabs(c), fabs(d)) <= D) return true;
  for (int i = 0; i < 4; i++) {
    ld x = a + dx[i] * D;
    ld y = b + dy[i] * D;
    if (can2(x, y, D)) return true;
    x = c + dx[i] * D;
    y = d + dy[i] * D;
    if (can3(x, y, D)) return true;
  }
  return false;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  cin >> a >> b >> c >> d;
  ld L = 0;
  ld R = 2e9;
  for (int i = 0; i < 200; i++) {
    ld M = (L + R) / 2;
    if (can(M)) {
      R = M;
    } else {
      L = M;
    }
  }
  printf("%.18lf\n", (double)L);
  return 0;
}