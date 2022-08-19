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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int a, b, s, t, m;

inline ll g(int i) { return (ll)b*(i-1)+a;}
inline ll sum(int l, int r) {
  ll xl = g(l), xr = g(r);
  return (xl+xr)*(r-l+1)/2;
}
bool f(int x) {
  if (g(x) > t) return false;
  return sum(s,x) <= (ll)t*m;
}

int main(){
  int q;
  scanf("%d%d%d",&a,&b,&q);
  rep(qi,q) {
    scanf("%d%d%d",&s,&t,&m);
    int l = s, r = t+2, c;
    if (g(s) <= t) {
      while (l+1 < r) {
        c = (l+r)>>1;
        if (f(c)) l = c; else r = c;
      }
    } else l = -1;
    printf("%d\n",l);
  }
  return 0;
}