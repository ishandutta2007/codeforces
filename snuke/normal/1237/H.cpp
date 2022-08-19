#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); continue;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

vi solve(const vi& a) {
  int n = sz(a);
  vp p(n);
  rep(i,n) p[i] = P(a[i],1);
  vi res;
  auto rev = [&](int l) {
    int s = 0;
    rep(i,l) s += p[i].se, p[i].fi = -p[i].fi;
    res.pb(s);
    reverse(p.begin(), p.begin()+l);
  };
  while (n) {
    int mi = -1;
    vi is(n+1);
    rep(i,n) {
      is[abs(p[i].fi)] = i+1;
      maxs(mi,p[i].fi);
    }
    if (mi != -1) {
      int ai = is[mi];
      if (mi == n) {
        rev(ai);
        rev(n);
      } else {
        int bi = is[mi+1];
        if (bi < ai) {
          rev(ai);
          rev(ai-bi);
        } else {
          rev(bi);
          rev(bi-ai);
        }
      }
    } else {
      rrep(i,n-1) if (is[i] > is[i+1]) mi = i;
      if (mi != -1) {
        int ai = is[mi], bi = is[mi+1];
        rev(bi);
        rev(ai-1);
      } else {
        rep(i,n) {
          rev(n);
          if (n > 1) rev(n-1);
        }
        break;
      }
    }
    if (mi == n) {
      p.pop_back();
    } else {
      rep(i,n) {
        int sg = p[i].fi<0?-1:1;
        int x = abs(p[i].fi);
        is[x] = i;
        if (x > mi) --x;
        p[i].fi = x*sg;
      }
      p[is[mi]].se += p[is[mi+1]].se;
      p.erase(p.begin()+is[mi+1]);
    }
    --n;
  }
  return res;
}

int main() {
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    string s, t;
    cin>>s>>t;
    vvi is(4);
    int n = sz(s)/2;
    rep(i,n) {
      int x = (t[i*2]-'0')*2+(t[i*2+1]-'0');
      is[x].pb(i+1);
    }
    vi a;
    rep(i,n) {
      int x = (s[i*2]-'0')*2+(s[i*2+1]-'0');
      if (sz(is[x])) {
        a.pb(is[x].back());
        is[x].pop_back();
      } else {
        if (pcnt(x) == 1) {
          x ^= 3;
          if (sz(is[x])) {
            a.pb(-is[x].back());
            is[x].pop_back();
            continue;
          }
        }
        break;
      }
    }
    if (sz(a) != n) dame;
    vi ans = solve(a);
    assert(sz(ans) <= sz(s));
    rep(i,sz(ans)) assert(0 < ans[i] && ans[i] <= n);
    rep(i,sz(ans)) ans[i] *= 2;
    rep(i,sz(ans)) reverse(s.begin(),s.begin()+ans[i]);
    assert(s == t);
    cout<<sz(ans)<<endl;
    cout<<ans<<endl;
  }
  return 0;
}