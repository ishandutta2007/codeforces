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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //<^>v

// Binary Indexed Tree
//
// Z algorithm
struct Z {
  vi a;
  Z(){}
  Z(string s):a(s.size()) {
    int n = s.size(); a[0] = n;
    for (int i=1,j=0;i<n;) {
      while (i+j<n && s[j]==s[i+j]) ++j;
      a[i] = j;
      int k = !!j;
      while (i+k<n && k+a[k]<j) a[i+k] = a[k], ++k;
      i += k+!j; j -= k;
    }
  }
};
//

int d[MX];
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

struct bit{
  typedef mint TT;
  vector<TT> d; int x2;
  bit(){}
  bit(int mx){ x2 = 1; while(x2 < mx) x2 <<= 1; d.resize(x2+1);}
  void add(int i, TT x=1){ for(i++;i<=x2;i+=i&-i) d[i] += x;}
  TT sum(int i){i++;
    TT x = 0; for(;i;i-=i&-i) x += d[i];
    return x;
  }
};


int main(){
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  Z z(t+s);
  int ts = t.size();
  rep(i,s.size()) d[i] = -1;
  rep(i,s.size()) {
    if (z.a[ts+i] >= ts) d[i] = 0;
  }
  int n = s.size();
  drep(i,n-1) if(d[i] == -1 && d[i+1] != -1) d[i] = d[i+1]+1;
  bit dp(MX);
  dp.add(0,1);
  dp.add(1,-1);
  rep(i,n) {
    mint now = dp.sum(i);
    dp.add(i+1,now);
    dp.add(i+2,mint(0)-now);
    if (d[i] == -1) continue;
    int nx = i+d[i]+ts;
    dp.add(nx,now);
  }
  mint ans = dp.sum(n);
  ans = ans-1;
  cout << ans.x << endl;
  return 0;
}