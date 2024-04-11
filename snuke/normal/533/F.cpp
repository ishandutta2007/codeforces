#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

/* debug output
#define pri(...) fprintf(stderr,"Debug: " __VA_ARGS__)
//*/#define pri(...)

string s, t;

struct H {
  const int p1 = 999901571;
  const int p2 = 999900301;
  const int m1 = 1000000097;
  const int m2 = 1000000663;
  int n, q1, q2;
  H(int n):n(n) {
    q1 = q2 = 1;
    rep(i,n) q1 = (ll)q1*p1%m1;
    rep(i,n) q2 = (ll)q2*p2%m2;
  }
  P f(P a, int x, int y=0) {
    P r;
    r.fi = ((ll)a.fi*p1 - (ll)y*q1 + m1 + x)%m1;
    r.se = ((ll)a.se*p2 - (ll)y*q2 + m2 + x)%m2;
    return r;
  }
};

P a[26], b[26][MX];
int sa[26];

int main(){
  int n, m;
  cin >> m >> n >> t >> s;
  H h(n);
  rep(j,26) {
    char c = 'a'+j;
    a[j] = P(0,0);
    rep(i,n) a[j] = h.f(a[j],s[i]==c);
  }
  rep(j,26) {
    char c = 'a'+j;
    b[j][0] = P(0,0);
    rep(i,n) b[j][0] = h.f(b[j][0],t[i]==c);
    rep(i,m-n) {
      b[j][i+1] = h.f(b[j][i],t[i+n]==c,t[i]==c);
    }
  }
  rep(i,26) sa[i] = INF;
  rep(i,n) mins(sa[s[i]-'a'],i);
  vi ans;
  rep(i,m-n+1) {
    bool ok = true;
    vi used(26,0);
    pri("%d\n",i);
    rep(j,26) {
      if (sa[j] == INF) continue;
      if (used[j]) continue;
      used[j] = 1;
      int k = t[i+sa[j]]-'a';
      if (j != k && used[k]){ ok = false; pri("%d %d\n",j,k); break;}
      if (a[j] != b[k][i]){ ok = false;pri("a %d %d\n",j,k);  break;}
      if (a[k] != b[j][i]){ ok = false; pri("b %d %d\n",j,k); break;}
      used[k] = 1;
    }
    if (ok) ans.pb(i+1);
  }
  cout << sz(ans) << endl;
  priv(ans);
  return 0;
}