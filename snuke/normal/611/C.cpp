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

const int MX = 505, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int h, w;
string s[505];
int x[MX][MX];
int y[MX][MX];

inline int get(int z[MX][MX], int a, int b, int c, int d) {
  return z[c][d] - z[a][d] - z[c][b] + z[a][b];
}

int main() {
  scanf("%d%d",&h,&w);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w-1) if (s[i][j] == '.' && s[i][j+1] == '.') x[i+1][j+1] = 1;
  rep(i,h-1)rep(j,w) if (s[i][j] == '.' && s[i+1][j] == '.') y[i+1][j+1] = 1;
  // rep(i,h){rep(j,w) printf("%d",x[i][j]); puts("");}
  rrep(i,h)rrep(j,w) x[i][j+1] += x[i][j];
  rrep(i,h)rrep(j,w) x[i+1][j] += x[i][j];
  rrep(i,h)rrep(j,w) y[i][j+1] += y[i][j];
  rrep(i,h)rrep(j,w) y[i+1][j] += y[i][j];
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    int a, b, c, d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    --a; --b;
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    int ans = 0;
    ans += get(x,a,b,c,d-1);
    ans += get(y,a,b,c-1,d);
    printf("%d\n", ans);
  }
  
  return 0;
}