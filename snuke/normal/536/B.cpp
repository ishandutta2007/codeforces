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
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

// Z algorithm
struct Z {
  int n;
  vi a;
  Z(){}
  Z(string& s):a(s.size()) {
    n = s.size(); a[0] = n;
    for (int i=1,j=0;i<n;) {
      while (i+j<n && s[j]==s[i+j]) ++j;
      a[i] = j;
      int k = !!j;
      while (i+k<n && k+a[k]<j) a[i+k] = a[k], ++k;
      i += k+!j; j -= k;
    }
  }
  bool ok(int d) {
    if (d >= n) return true;
    return a[d] == n-d;
  }
};
//

char in[MX];
string s;
int p[MX];

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x((x%mod+mod)%mod){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//

int main(){
  int n, m, l;
  scanf("%d%d%s",&n,&m,in);
  rep(i,m) {
    int a;
    scanf("%d",&a);
    p[a-1] = 1;
  }
  s = in;
  Z z(s);
  l = s.size();
  //rep(i,l) printf("%d %d\n",i,z.ok(i));
  int t = 0, r = -INF;
  rep(i,n) {
    if (p[i]) {
      if (!z.ok(i-r)) {
        puts("0");
        return 0;
      }
      r = i;
    } else {
      if (r+l <= i) t++;
    }
  }
  mint ans = 1;
  rep(i,t) ans *= 26;
  printf("%I64d\n",ans.x);
  return 0;
}