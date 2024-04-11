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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

// Segment tree (RMQ type)
struct seg{
	typedef vi TT;
	vector<TT> d; int x2;
	seg(){}
	seg(int mx){
    x2 = 1; while(x2 < mx) x2 <<= 1;
    d.resize(x2<<1);
  }
	void fil(){
    drep(i,x2) {
      d[i] = d[i<<1];
      d[i].insert(d[i].end(),rng(d[i<<1|1]));
      sort(rng(d[i]));
    }
  }
	int qu(int a, int b, int x, int i=1, int l=0, int r=-1){
		if (r == -1) r = x2;
		if(a <= l && r <= b) {
      return lower_bound(rng(d[i]),x)-d[i].begin();
    }
		int c = (l+r)>>1; int res = 0;
		if(a < c) res += qu(a,b,x,i<<1,l,c);
		if(c < b) res += qu(a,b,x,i<<1|1,c,r);
		return res;
	}
};
//

int a[MX];
int main(){
  int n;
  scanf("%d",&n);
  rep(i,n) scanf("%d",&a[i]);
  seg t(n+2);
  rep(i,n) t.d[t.x2+i] = vi(1,a[i]);
  t.fil();
  vi as;
  rrep(k,n-1) {
    int ans = 0;
    rep(i,n) {
      int l = i*k+1, r = l+k;
      if (l >= n) break;
      r = min(r,n);
      ans += t.qu(l,r,a[i]);
    }
    as.pb(ans);
  }
  priv(as);
  return 0;
}