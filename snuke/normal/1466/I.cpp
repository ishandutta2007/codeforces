#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

int b;
struct B {
  vi a;
  B(int x=0):a(b,x) {}
  int& operator[](int i) { return a[i];}
  int operator[](int i) const { return a[i];}
  bool operator<(const B& x) const {
    rep(i,b) if (a[i] != x[i]) return a[i]<x[i];
    return false;
  }
  bool operator<=(const B& x) const {
    rep(i,b) if (a[i] != x[i]) return a[i]<x[i];
    return true;
  }
  string str() const {
    string s(b,'0');
    rep(j,b) s[j] += a[j];
    return s;
  }
  B middle(const B& r) const {
    B res;
    rep(i,b) {
      res[i] = r[i];
      if (a[i] != r[i]) break;
    }
    return res;
  }
  B dec() const {
    B res;
    res.a = a;
    for (int i = b-1; i >= 0; --i) {
      if (res[i]) { res[i] = 0; break;}
      res[i] = 1;
    }
    return res;
  }
};
ostream& operator<<(ostream&o,const B&a){o<<a.str();return o;}

struct Solver {
  int n;

  bool f(int i, const B& a) {
    cout<<i+1<<" "<<a.dec()<<endl;
    string s; cin>>s;
    return s == "yes";
  }
  void answer(const B& a) {
    cout<<0<<" "<<a<<endl;
  }
  void solve() {
    cin >> n >> b;

    B l, r(1);
    v(B) rs(n,B(1));
    stack<B> s;
    queue<int> q;
    rep(i,n) q.push(i);
    while (sz(q)) {
      int i = q.front(); q.pop();
      while (l < rs[i]) {
        while (r <= l && sz(s)) { r = s.top(); s.pop();}
        B x = l.middle(r);
        if (f(i,x)) {
          l = x;
          if (sz(s)) { r = s.top(); s.pop();}
        } else {
          s.push(r);
          r = rs[i] = x.dec();
          q.push(i);
          break;
        }
      }
    }

    answer(l);
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}