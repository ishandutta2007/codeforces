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
char s[1000010];
int z[1000010];
void calcZ(char* s, int* z) {
  int n = strlen(s);
  int mxr = 1;
  int mxl = 1;
  for (int i = 1; i < n; i++) {
    int cur = max(0, min(z[i - mxl], mxr - i));
    while (s[cur] == s[i + cur]) {
      cur++;
      mxl = i;
      mxr = i + cur;
    }
    z[i] = cur;
  }
}
int n, k;
int sum[1000010];
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  calcZ(s, z);
  for (int x = 1; x <= n / k; x++) {
    if (z[x] >= (k - 1) * x) {
      int p = k * x;
      sum[p - 1]++;
      sum[p + min(x, z[p])]--;
    }
  }
  int o = 0;
  for (int i = 0; i < n; i++) {
    o += sum[i];
    if (o > 0) printf("1"); 
      else printf("0");
  }
  printf("\n");
  return 0;
}