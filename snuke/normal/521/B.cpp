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
inline int in() { int x; scanf("%d",&x); return x;}
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

// Mod int
const int mod = 1000000009;
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

map<P,int> d;

vi to[MX], ot[MX];
bool used[MX];

inline bool fra(int v) {
  if (used[v]) return false;
  int cnt = 0;
  for (int u : to[v]) if (!used[u]) cnt++;
  return (cnt == 1);
}
bool can(int v) {
  for (int u : ot[v]) {
    if (fra(u)) return false;
  }
  return true;
}

int main(){
  int n;
  scanf("%d",&n);
  rep(i,n) {
    int x, y;
    scanf("%d%d",&x,&y);
    d[P(x,y)] = i;
  }
  for (auto p : d) {
    int v = p.se;
    int x = p.fi.fi, y = p.fi.se;
    rep(i,3) {
      P r(x-1+i,y-1);
      if (d.count(r)) {
        int u = d[r];
        to[v].pb(u);
        ot[u].pb(v);
      }
    }
  }
  priority_queue<int> q1;
  priority_queue<int,vector<int>,greater<int> > q2;
  rep(i,n) q1.push(i);
  rep(i,n) q2.push(i);
  mint ans = 0;
  int turn = 0;
  while (q1.size() && q2.size()) {
    int v;
    if (turn == 0) {
      v = q1.top(); q1.pop();
    } else {
      v = q2.top(); q2.pop();
    }
    if (used[v]) continue;
    if (!can(v)) continue;
    used[v] = true;
    ans = ans*n+v;
    for (int u : to[v]) {
      if (used[u]) continue;
      q1.push(u);
      q2.push(u);
    }
    turn ^= 1;
    //printf("v : %d\n",v);
    //rep(i,n) printf("%d : %d %d\n",i,rc[i],deg[i]);
  }
  cout << ans.x << endl;
  return 0;
}