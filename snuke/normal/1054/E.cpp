#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
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
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
typedef v(string) vs;
typedef v(vs) vvs;
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

char ins[MX];

int h, w;
void inp(vvs& s) {
  s = vvs(h,vs(w));
  rep(i,h)rep(j,w) {
    scanf("%s",ins);
    s[i][j] = ins;
  }
}

void calc(vvs& s, vvi& a, vvi& as, bool rev) {
  rep(i,h)rep(j,w) {
    string ns = s[i][j];
    if (!rev) reverse(rng(ns));
    for (char c : ns) {
      if (c == '0') {
        if (i == 0) {
          int nj = (j+1)%w;
          a[0][nj]++;
          as.pb({0,j,0,nj});
        } else {
          a[0][j]++;
          as.pb({i,j,0,j});
        }
      } else {
        if (i == 1) {
          int nj = (j+1)%w;
          a[1][nj]++;
          as.pb({1,j,1,nj});
        } else {
          a[1][j]++;
          as.pb({i,j,1,j});
        }
      }
    }
  }
  if (rev) {
    rep(i,sz(as)) {
      swap(as[i][0],as[i][2]);
      swap(as[i][1],as[i][3]);
    }
    reverse(rng(as));
  }
}

int main() {
  scanf("%d%d",&h,&w);
  vvs s, t;
  inp(s);
  inp(t);

  vvi a(h,vi(w));
  vvi b(h,vi(w));

  vvi as, bs;
  calc(s,a,as,false);
  calc(t,b,bs,true);

  rep(i,2) {
    vi q;
    rep(j,w) {
      rep(k,a[i][j]-b[i][j]) q.pb(j);
    }
    rep(j,w) {
      rep(k,b[i][j]-a[i][j]) {
        int nj = q.back(); q.pop_back();
        as.pb({i,nj,i,j});
      }
    }
  }

  as.insert(as.end(), rng(bs));

  // for (vi na : as) {
  //   int si = na[0], sj = na[1];
  //   int ti = na[2], tj = na[3];
  //   cerr<<na<<endl;
  //   assert(sz(s[si][sj]));
  //   s[ti][tj].insert(s[ti][tj].begin(), s[si][sj].back());
  //   s[si][sj].pop_back();
  //   cout<<s<<endl;
  // }

  cout<<sz(as)<<endl;
  rep(i,sz(as)) {
    rep(j,4) as[i][j]++;
    priv(as[i]);
  }
  return 0;
}