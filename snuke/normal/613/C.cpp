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
#include <numeric>
#include <cctype>
#include <bitset>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m;
int a[26];
int b[26];

bool good() {
  int o = 0;
  rep(i,m) if (b[i]%2) o++;
  return o <= 1;
}
string get() {
  string s;
  string o;
  rep(i,m) if (b[i]%2) o += 'a'+i;
  rep(i,m)rep(j,b[i]/2) s += 'a'+i;
  string res = s;
  reverse(rng(s));
  res += o+s;
  return res;
}

int main() {
  scanf("%d",&m);
  rep(i,m) scanf("%d",&a[i]);
  n = 0;
  rep(i,m) n += a[i];
  string ans;
  for (int c = 1; c <= n; ++c) {
    if (n%c) continue;
    bool ok = true;
    int d = n/c;
    int nd = d;
    if (nd%2 == 0) nd /= 2;
    rep(i,m) if (a[i]%nd) ok = false;
    if (!ok) continue;
    rep(i,m) b[i] = a[i]/nd;
    if (good()) {
      cout<<d<<endl;
      string t = get();
      rep(i,nd) ans += t;
      cout<<ans<<endl;
      return 0;
    }
  }
  rep(i,m)rep(j,a[i]) ans += 'a'+i;
  cout<<0<<endl;
  cout<<ans<<endl;
  return 0;
}