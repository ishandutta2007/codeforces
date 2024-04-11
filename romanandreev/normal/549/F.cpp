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
const int inf = (int)1e9 + 10;
int n, k, K;
const int maxn = (int)1e6 + 10;
int a[maxn];
int lf[maxn];
int rg[maxn];
int s[maxn];
pair<int, int> S[maxn];
vector<int> M[maxn];
int calc(int l, int r, int x) {
  return upper_bound(all(M[x]), r) - lower_bound(all(M[x]), l);
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &k);
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = (s[i - 1] + a[i]) % k;
  }
  for (int i = 0; i <= n; i++) {
    M[s[i]].pb(i);
  }
  K = 0;
  S[K++] = mp(inf, 0);
  for (int i = 1; i <= n; i++) {  
    while (S[K - 1].x <= a[i]) {
      K--;
    }
    lf[i] = S[K - 1].y + 1;
    S[K++] = mp(a[i], i);
  }
  K = 0;
  S[K++] = mp(inf, n + 1);
  for (int i = n; i >= 1; i--) {  
    while (S[K - 1].x < a[i]) {
      K--;
    }
    rg[i] = S[K - 1].y - 1;
    S[K++] = mp(a[i], i);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (abs(lf[i] - i) <= abs(rg[i] - i)) {
      for (int j = lf[i]; j <= i; j++) {
        ans += calc(i, rg[i], (s[j - 1] + a[i]) % k);
      }
    } else {
      for (int j = i; j <= rg[i]; j++) {
        ans += calc(lf[i] - 1, i - 1, (s[j] - (a[i] % k) + k) % k);
      }
    }
  }
  cout << ans - n << endl;
  return 0;
}