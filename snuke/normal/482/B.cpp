#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[30][MX], ql[MX], qr[MX], qx[MX];

// Binary Indexed Tree
struct bit{
	typedef int TT;
	vector<TT> d; int x2;
	bit(){}
	bit(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2+1);}
	void add(int i, TT x=1){ i++;for(;i<=x2;i+=i&-i) d[i] += x;}
	TT sum(int i){
    i++;
		TT x = 0; for(;i;i-=i&-i) x += d[i];
		return x;
	}
};
//

int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  rep(i,m) { 
    int l, r, x;
    scanf("%d%d%d",&l,&r,&x); l--;
    rep(j,30) {
      if (x>>j&1) {
        a[j][l]++; a[j][r]--;
      }
    }
    ql[i] = l;
    qr[i] = r;
    qx[i] = x;
  }
  rep(j,30)rep(i,n) a[j][i+1] += a[j][i];
  rep(j,30) {
    bit d(n+5);
    rep(i,n) if(!a[j][i]) d.add(i);
    rep(i,m) {
      if (qx[i]>>j&1) continue;
      if (d.sum(qr[i]-1)-d.sum(ql[i]-1) == 0) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  rep(i,n) {
    int x = 0;
    rep(j,30) if (a[j][i]) x |= 1<<j;
    printf("%d",x);
    if (i == n-1) puts(""); else printf(" ");
  }
  
  return 0;
}