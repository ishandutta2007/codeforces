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
#define hash hash_fdfsdfsdgfs

#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n;

int d[1000000];
int nx_suff[1000000];
int nx_pref[1000000];
vector<int> ls;
const int sh = 1 << 19;
int rm[2 * sh + 10];
const int inf = (int)2e9 + 10;
void add(int x, int v) {
  int p = (int)(lower_bound(all(ls), x) - ls.begin());
  p += sh;
  while (p >= 1) {
    rm[p] = min(rm[p], v);
    p /= 2;
  }
}
int get_min(int x) {
  int l = sh;
  int r = (int)(lower_bound(all(ls), x) - ls.begin()) + sh;
  int res = inf;
  while (l <= r) {
    res = min(res, rm[l]);
    res = min(res, rm[r]);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return res;
}
int x[1000000];
int main(){
  //assert(freopen(problem_name".out","wt",stdout));
  //assert(freopen(problem_name".in","rt",stdin));
  scanf("%d", &n);           
  for (int i = 0; i <= n + 1; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
  }
  for (int i = 0; i <= 2 * sh + 3; i++) {
    rm[i] = inf;
  }
  {
    vector<int> st;
    st.pb(0);
    nx_pref[0] = inf;
    for (int i = 1; i <= n + 1; i++) {
      while (sz(st) >= 2 && x[i] - x[st[sz(st) - 2]] > 2 * d[st[sz(st) - 1]]) {
        st.pop_back();
      }
      st.pb(i);
      nx_pref[i] = (int)min((ll)inf, (ll)(2 * d[i] + x[st[sz(st) - 2]]));
    }
  }
  {
    vector<int> st;
    st.pb(n + 1);
    for (int i = n; i >= 0; i--) {       
      while (sz(st) >= 2 && x[st[sz(st) - 2]] - x[i] > 2 * d[st[sz(st) - 1]]) {
        st.pop_back();
      }
      st.pb(i);
      nx_suff[i] = -2 * d[i] + x[st[sz(st) - 2]];
    }
    nx_suff[n + 1] = -inf;
  }
  
  for (int i = 0; i <= n + 1; i++) {
    ls.pb(x[i]);
    ls.pb(nx_pref[i]);
    ls.pb(nx_suff[i]);
  }
  image(ls);
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    if (nx_pref[i] >= x[n + 1]) {    
      ans = 0;                  
    }
  }  
  add(nx_suff[n + 1], x[n + 1]);
  for (int i = n; i >= 0; i--) {
    //cerr<<nx_pref[i]<<" "<<nx_suff[i]<<endl;
    if (nx_pref[i] > x[i]) {
      int val = get_min(nx_pref[i]);
      //cerr<<val<<endl;
      if (val < inf) {
        ans = min(ans, val - x[i]);
      }
    }
    if (nx_suff[i] < x[i]) {
      add(nx_suff[i], x[i]);
    }
  }
  printf("%.4f\n", (double)ans * 0.5);
  return 0;
}