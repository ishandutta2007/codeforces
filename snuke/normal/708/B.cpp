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
#include <cassert>
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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("Impossible"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

bool ok;
int f(int x) {
  for (ll i = 0; i < MX; ++i) if (i*(i-1)/2 == x) return i;
  ok = false;
  return 0;
}

bool solve(ll a, ll b, ll ab, ll ba) {
  if (ab+ba != a*b) return false;
  if (!a && !b) return false;
  if (!a) { cout<<string(b,'1')<<endl; return true;}
  if (!b) { cout<<string(a,'0')<<endl; return true;}
  string s;
  int x = ba/b, y = a-x;
  int l = 0;
  if (ba%b) {
    y--;
    l = ba%b;
  }
  s += string(y,'0');
  s += string(l,'1');
  if (ba%b) s += '0';
  s += string(b-l,'1');
  s += string(x,'0');
  cout<<s<<endl;
  return true;
}

int main() {
  vi x(4);
  cin >> x;
  ok = true;
  int a = f(x[0]), b = f(x[3]);
  if (!ok) dame;
  rep(i,2)rep(j,2) {
    if (a && i) continue;
    if (b && j) continue;
    if (solve(a+i, b+j, x[1], x[2])) return 0;
  }
  dame;
  return 0;
}