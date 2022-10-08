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
ll c, hr, hb, wr, wb;
ll get1(ll x) {
  ll y = (c - x * wr) / wb;
  return x * hr + y * hb;
}
ll get2(ll y) {
  ll x = (c - y * wb) / wr;
  return x * hr + y * hb;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif  
  cin >> c >> hr >> hb >> wr >> wb;
  ll R = c / wr;
  ll ans = get1(0);
  for (ll i = 0; i <= min((ll)1e5, R); i++) {
    ans = max(ans, get1(i));
  }
  R = c / wb;
  for (ll i = 0; i <= min((ll)1e5, R); i++) {
    ans = max(ans, get2(i));
  }
  cout << ans << endl;
  return 0;
}