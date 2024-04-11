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
#define df(x) int x = in()
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

multiset<int> s;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

int main() {
  int n;
  scanf("%d",&n);
  vi d;
  rep(i,n)rep(j,n) d.pb(in());
  int m = n*n;
  rep(i,m) s.insert(d[i]);
  vi a;
  rep(i,n) {
    int x = *(s.rbegin());
    s.erase(s.find(x));
    rep(i,sz(a)) s.erase(s.find(gcd(a[i],x)));
    rep(i,sz(a)) s.erase(s.find(gcd(a[i],x)));
    a.pb(x);
    // cout<<x<<" "<<sz(s)<<endl;
  }
  priv(a);
  return 0;
}