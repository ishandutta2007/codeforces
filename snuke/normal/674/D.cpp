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
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
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

int p[MX];
int deg[MX];
ll t[MX];
ll d[MX];
multiset<ll> mas;
multiset<ll> nas[MX];

inline ll s(int v) { return t[v]/deg[v];}
inline ll ss(int v) { return t[v]-s(v)*(deg[v]-1);}
inline void del(multiset<ll>& s, ll x, ll y) {
  ll l = *(s.begin());
  ll r = *(s.rbegin());
  s.erase(s.find(x));
  if (sz(s)) {
    ll nl = *(s.begin());
    ll nr = *(s.rbegin());
    if (l != nl) {
      mas.erase(mas.find(l+y));
      mas.insert(nl+y);
    }
    if (r != nr) {
      mas.erase(mas.find(r+y));
      mas.insert(nr+y);
    }
  } else {
    mas.erase(mas.find(l+y));
    mas.erase(mas.find(r+y));
  }
}
inline void add(multiset<ll>& s, ll x, ll y) {
  if (sz(s)) {
    ll l = *(s.begin());
    ll r = *(s.rbegin());
    s.insert(x);
    ll nl = *(s.begin());
    ll nr = *(s.rbegin());
    if (l != nl) {
      mas.erase(mas.find(l+y));
      mas.insert(nl+y);
    }
    if (r != nr) {
      mas.erase(mas.find(r+y));
      mas.insert(nr+y);
    }
  } else {
    s.insert(x);
    ll nl = *(s.begin());
    ll nr = *(s.rbegin());
    mas.insert(nl+y);
    mas.insert(nr+y);
  }
}
void sp(int v, int sg) {
  int u = p[v];
  if (u != -1) {
    if (p[u] != -1) del(nas[p[u]],d[u],s(p[u]));
    d[u] += s(v)*sg;
    if (p[u] != -1) add(nas[p[u]],d[u],s(p[u]));
  }
  if (u != -1) del(nas[u],d[v],s(u));
  d[v] += ss(v)*sg;
  if (u != -1) add(nas[u],d[v],s(u));
}
void f(int v, ll x) {
  ll y = s(v);
  if (sz(nas[v])) {
    ll l = *(nas[v].begin());
    ll r = *(nas[v].rbegin());
    mas.erase(mas.find(l+x));
    mas.erase(mas.find(r+x));
    mas.insert(l+y);
    mas.insert(r+y);
  }
}
void discon(int v) {
  int u = p[v];
  if (u == -1) return;
  sp(u,-1); sp(v,-1);
  ll au = s(u), av = s(v);
  deg[v]--; deg[u]--;
  f(u,au); f(v,av);
  del(nas[u],d[v],s(u));
  p[v] = -1;
  sp(u,1); sp(v,1);
}
void con(int v, int u) {
  discon(v);
  sp(u,-1); sp(v,-1);
  p[v] = u;
  add(nas[u],d[v],s(u));
  ll au = s(u), av = s(v);
  deg[v]++; deg[u]++;
  f(u,au); f(v,av);
  sp(u,1); sp(v,1);
}

int main() {
  int n, q;
  scanf("%d%d",&n,&q);
  rep(i,n) scanf("%I64d",&t[i]);
  rep(i,n) p[i] = -1;
  rep(i,n) deg[i] = 1;
  rep(i,n) d[i] = ss(i);
  rep(i,n) {
    int a;
    scanf("%d",&a); --a;
    con(i,a);
  }
  rep(qi,q) {
    int ty;
    scanf("%d",&ty);
    if (ty == 1) {
      int a, b;
      scanf("%d%d",&a,&b); --a; --b;
      con(a,b);
    } else if (ty == 2) {
      int a;
      scanf("%d",&a); --a;
      printf("%I64d\n",d[a]+s(p[a]));
    } else {
      ll l = *(mas.begin());
      ll r = *(mas.rbegin());
      printf("%I64d %I64d\n",l,r);
    }
  }
  return 0;
}