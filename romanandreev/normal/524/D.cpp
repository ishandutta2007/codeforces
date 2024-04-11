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
const int MX = 24 * 60 * 60;
int n,M,T;
vector<int> cnt[MX + 1];
int up[20001];
int go(int x) {
  if (up[x] == x) {
    return x;
  }
  return up[x] = go(up[x]);
}
void mergee(int x, int y) {
  x = go(x);
  y = go(y);
  assert(x != y);
  up[x] = y;
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d %d", &n, &M, &T);
  for (int i = 0; i < n; i++) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    cnt[(hh * 60 + mm) * 60 + ss].pb(i);
    up[i] = i;
  }
  set<pair<int, int> > S; 
  int mx = 0;
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < sz(cnt[i]); j++) {
      S.insert(mp(i + T - 1, cnt[i][j]));
    }
    while (sz(S) > 0 && S.begin()->x < i) {
      S.erase(*S.begin());
    }
    while (sz(S) > M) {
      pair<int, int> v1 = *S.rbegin();
      S.erase(v1);
      pair<int, int> v2 = *S.rbegin();
      S.erase(v2);      
      mergee(v1.y, v2.y);
      S.insert(v1);
    }
    mx = max(mx, sz(S));
  }
  if (mx < M) {
    printf("No solution\n");
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    ans.pb(go(i));
  }
  image(ans);
  printf("%d\n", sz(ans));
  for (int i = 0; i < n; i++) {
    printf("%d\n", lower_bound(all(ans), go(i)) - ans.begin() + 1);
  }
  return 0;
}