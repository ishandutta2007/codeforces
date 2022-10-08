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
int a[100000];
pair<ll, ll> calc(int v, int n) {
  if (n == 0) {
    return mp(0, 0);
  }
  pair<ll, ll> l = calc(v * 2, n - 1);
  pair<ll, ll> r = calc(v * 2 + 1, n - 1);
  ll s = max(l.x + a[v * 2], r.x + a[v * 2 + 1]);
  ll ans = l.y + r.y + 2 * s - (l.x + a[v * 2]) - (r.x + a[v * 2 + 1]);
  return mp(s, ans);
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int n;
  scanf("%d", &n);
  for (int i = 2; i < (1 << (n + 1)); i++) {
    scanf("%d", &a[i]);
  }                    
  cout <<  calc(1, n).y << endl;
  return 0;
}