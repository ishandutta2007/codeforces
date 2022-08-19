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
#define pcnt __builtin_popcountll
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

const int n = 8, n2 = 1<<n, n1 = n2-1;

map<int,string> me, mt, mf;

bool up(map<int,string>& mp, int x, string now) {
  if (!mp.count(x)) {
    mp[x] = now;
    return true;
  }
  if (sz(mp[x]) < sz(now)) return false;
  if (sz(mp[x]) == sz(now) && mp[x] <= now) return false;
  mp[x] = now;
  return true;
}
void init() {
  vi ne, nt, nf;
  rep(i,3) {
    int x = 0;
    rep(j,8) if (j>>i&1) x |= 1<<j;
    me[x] = string(1,'z'-i); ne.pb(x);
    mt[x] = string(1,'z'-i); nt.pb(x);
    mf[x] = string(1,'z'-i); nf.pb(x);
  }
  bool upd = true;
  while (upd) {
    upd = false;
    {// E|T, T
      for (auto q : mt) {
        int x = q.fi;
        if (up(me,x,q.se)) upd = true;
        auto mp = me;
        for (auto p : mp) {
          int nx = p.fi|x;
          if (up(me,nx,p.se+"|"+q.se)) upd = true;
        }
      }
    }
    {// T&F, F
      for (auto q : mf) {
        int x = q.fi;
        if (up(mt,x,q.se)) upd = true;
        auto mp = mt;
        for (auto p : mp) {
          int nx = p.fi&x;
          if (up(mt,nx,p.se+"&"+q.se)) upd = true;
        }
      }
    }
    { // !F
      auto mp = mf;
      for (auto p : mf) {
        int nx = p.fi^n1;
        if (up(mf,nx,"!"+p.se)) upd = true;
      }
    }
    { // (E)
      for (auto p : me) {
        if (up(mf,p.fi,"("+p.se+")")) upd = true;
      }
    }
  }
  // cout<<sz(me)<<endl;
  // cout<<sz(mt)<<endl;
  // cout<<sz(mf)<<endl;
}

int main() {
  init();
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    string s;
    cin>>s;
    reverse(rng(s));
    int x = 0;
    rep(i,n) x = x<<1|(s[i]-'0');
    cout<<me[x]<<endl;
  }
  // rep(x,256) cout<<me[x]<<endl;
  return 0;
}