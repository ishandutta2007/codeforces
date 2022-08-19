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
inline int getInt() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Binary Indexed Tree
struct bit {
  typedef int TT;
  int n; vector<TT> d;
  bit() {}
  bit(int mx): n(mx+1), d(mx+1) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  TT sum(int i) {
    TT x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//

// fast set
int bsr(ull x) { return 63^__builtin_clzll(x);}
int bsf(ull x) { return __builtin_ctzll(x);}
struct faset {
  int n, h;
  vv(ull) seg;
  faset() {}
  faset(int n):n(n) {
    while (n > 1) {
      n = (n+63)>>6;
      seg.pb(v(ull)(n));
    }
    h = sz(seg);
  }
  bool count(int x) const {
    int d = x>>6, r = x&63;
    return seg[0][d]>>r&1;
  }
  void insert(int x) {
    rep(i,h) {
      ull b = 1ull<<(x&63);
      x >>= 6;
      seg[i][x] |= b;
    }
  }
  void erase(int x) {
    rep(i,h) {
      ull b = 1ull<<(x&63);
      x >>= 6;
      seg[i][x] &= ~b;
      if (seg[i][x]) break;
    }
  }
  // x <= res
  int nxt(int x) {
    rep(i,h) {
      int d = x>>6, r = x&63;
      if (d == sz(seg[i])) break;
      ull s = seg[i][d]>>r;
      if (s) {
        x += bsf(s);
        while (i--) {
          x = x<<6|bsf(seg[i][x]);
        }
        return x;
      }
      x = (x>>6)+1;
    }
    return n;
  }
  // res <= x
  int pre(int x) {
    rep(i,h) {
      if (x == -1) break;
      int d = x>>6, r = x&63;
      ull s = seg[i][d]<<(63^r);
      if (s) {
        x -= 63^bsr(s);
        while (i--) {
          x = x<<6|bsr(seg[i][x]);
        }
        return x;
      }
      x = (x>>6)-1;
    }
    return -1;
  }    
};
//

const int M = 26;
void solve() {
  string s;
  cin>>s;
  int n = sz(s);
  faset st(n);
  v(set<int>) ps(M);
  vi col(n);
  bit d(n+5);
  rep(i,n) d.add(i,1);
  rep(i,n-1) {
    if (s[i] == s[i+1]) {
      int a = s[i]-'a';
      st.insert(i);
      ps[a].insert(i);
      col[i] = a;
    }
  }
  vp ans;
  auto erase = [&](int i) {
    st.erase(i);
    ps[col[i]].erase(i);
  };
  auto add = [&](int l, int r) {
    int li = l;
    l = d.sum(l);
    r = d.sum(r);
    ans.eb(l+1,r);
    d.add(li+1, -(r-l));
  };
  while (1) {
    P mx(0,INF);
    rep(i,M) maxs(mx, P(sz(ps[i]),i));
    if (mx.fi == 0) break;
    int a = mx.se;
    int r = *ps[a].begin();
    int l = st.pre(r-1);
    if (l == -1) {
      rep(i,M) {
        if (i == a) continue;
        if (!sz(ps[i])) continue;
        r = *ps[i].begin();
        l = st.pre(r-1);
        if (col[l] != a) continue;
        break;
      }
    }
    if (l == -1) { // a only
      int ri = d.sum(r);
      ans.eb(1,ri);
      d.add(1, -ri);
      erase(r);
    } else {
      add(l, r);
      erase(l);
      erase(r);
    }
  }
  ans.eb(1, d.sum(n));
  printf("%d\n",sz(ans));
  for (P p : ans) {
    printf("%d %d\n",p.fi,p.se);
  }
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) solve();
  return 0;
}