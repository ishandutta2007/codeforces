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
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int a, b;

int main() {
  cin >> a >> b;
  if (a < b) {
    cout<<-1<<endl;
    return 0;
  }
  double ans = 1e20;
  {
    int d = a-b, w = b;
    int l = 0, r = INF/2;
    while (l+1<r) {
      int c = (l+r)>>1;
      double s = 1.0*d/(c*2);
      if (s+eps < w) r = c; else l = c;
      // cout<<s<<" "<<c<<" "<<w<<" "<<d<<endl;
    }
    l *= 2;
    if (l) {
      double s = 1.0*d/l;
      mins(ans,s);
    }
  }
  {
    int d = a+b, w = b;
    int l = 0, r = INF/2;
    while (l+1<r) {
      int c = (l+r)>>1;
      double s = 1.0*d/(c*2);
      if (s+eps < w) r = c; else l = c;
      // cout<<s<<" "<<c<<" "<<w<<" "<<d<<endl;
    }
    l = l*2;
    if (l) {
      double s = 1.0*d/l;
      mins(ans,s);
    }
  }
  printf("%.10f\n",ans);
  return 0;
}