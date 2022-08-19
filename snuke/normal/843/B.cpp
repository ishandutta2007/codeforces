#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
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
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
#include <random>
random_device _rd;
mt19937 _mt(_rd()+time(0));
inline int rnd(int n) { return _mt()%n;}
inline int rnd(int l, int r) { return _mt()%(r-l+1)+l;}


map<int,P> mp;
P f(int i) {
  if (mp.count(i)) return mp[i];
  cout<<'?'<<" "<<i<<endl;
  P res;
  cin>>res;
  mp[i] = res;
  return res;
}

int main() {
  int n = 50000;
  cin>>n;
  int si;
  cin>>si;
  int x;
  cin>>x;

  f(si);
  while (sz(mp) < min(n,1000)) {
    f(rnd(1,n));
  }

  P ans(INF,-1);
  P s(-1,si);
  for (auto p : mp) {
    if (p.se.fi >= x) {
      mins(ans, P(p.se.fi, p.fi));
    } else {
      maxs(s, P(p.se.fi, p.se.se));
    }
  }

  si = s.se;
  while (si != -1) {
    P res = f(si);
    if (res.fi >= x) {
      mins(ans,P(res.fi,si));
      break;
    }
    si = res.se;
  }

  int as = -1;
  if (ans.se != -1) as = ans.fi;
  cout<<'!'<<" "<<as<<endl;
  return 0;
}