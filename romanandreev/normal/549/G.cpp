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
int n;
int a[1000000];
int b[1000000];
int ls[1000000];

int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ls[i] = a[i] + i;
  }
  sort(ls, ls + n);
  for (int i = n - 1; i >= 0; i--) {
    b[i] = ls[i] - i;
  }
  bool good = true;
  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      good = false;
    }
    if (i + 1 < n && b[i + 1] < b[i]) {
      good = false;
    }
  }
  if (good) {
    for (int i = 0; i < n; i++) {
      printf("%d ", b[i]);
    }
  } else {
    printf(":(");
  }
  return 0;
}