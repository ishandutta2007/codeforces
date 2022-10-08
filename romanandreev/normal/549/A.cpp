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
char a[100][100];
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  int ans = 0;
  vector<char> f = {'f', 'a', 'c', 'e'};
  sort(all(f));
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      vector<char> s;
      s.pb(a[i][j]);
      s.pb(a[i + 1][j]);
      s.pb(a[i][j + 1]);
      s.pb(a[i + 1][j + 1]);
      sort(all(s));
      ans += s == f;
    }
  }
  cout << ans << endl;
  return 0;
}