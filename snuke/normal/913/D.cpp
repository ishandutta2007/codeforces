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
typedef pair<P,int> Q;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<Q> vq;
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



int main() {
  int n,t;
  scanf("%d%d",&n,&t);
  vq p(n);
  rep(i,n) {
    cin>>p[i].fi;
    p[i].se = i;
  }
  sort(rng(p));
  reverse(rng(p));
  P ans(-1,0);
  {
    priority_queue<int> q;
    int s = 0, c = 0;
    rep(i,n) {
      int a = p[i].fi.fi, b = p[i].fi.se;
      s += b; c++;
      q.push(b);
      while (s > t) {
        s -= q.top(); c--;
        q.pop();
      }
      int now = min(c,a);
      maxs(ans,P(now,i));
    }
  }
  {
    priority_queue<P> q;
    int s = 0, c = 0;
    vi d(n);
    rep(i,n) {
      int a = p[i].fi.fi, b = p[i].fi.se;
      s += b; c++; d[p[i].se] = 1;
      q.push(P(b,p[i].se));
      while (s > t) {
        s -= q.top().fi; c--;
        d[q.top().se] = 0;
        q.pop();
      }
      if (ans.se == i) {
        vi as;
        rep(j,n) if (d[j]) as.pb(j+1);
        while (sz(as) > a) as.pop_back();
        cout<<ans.fi<<endl;
        cout<<sz(as)<<endl;
        cout<<as<<endl;
        return 0;
      }
    }
  }
  cout<<0<<endl;
  cout<<0<<endl;
  cout<<""<<endl;
  return 0;
}