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
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 100005;

template<typename T> class CHT {
private:
    struct node {
        node *left, *right;
        const T inf;
        T a, b, l, r;
        node(const T _a, const T _b, const T _l, const T _r)
            : left(nullptr), right(nullptr), inf(numeric_limits<T>::max()),
                a(_a), b(_b), l(_l), r(_r){}
        T f(const T x) const {
            return (l <= x && x < r) ? (a * x + b) : inf;
        }
        T tf(const T x) const {
            return a * x + b;
        }
        bool isLine(const T _l, const T _r) const {
            return (l == _l) && (r == _r);
        }
    };
    void swap(node *x, node *y){
        std::swap(x->a, y->a), std::swap(x->b, y->b), std::swap(x->l, y->l), std::swap(x->r, y->r);
    }
    void _add_line(node *cur, node *nw, T l, T r){
        while(true){
            if(nw->f(l) < cur->f(l)) swap(cur, nw);
            if(cur->f(r - 1) <= nw->f(r - 1)) break;
            const T mid = (l + r) / 2;
            if(cur->f(mid) <= nw->f(mid)){
                if(!cur->right){
                    cur->right = new node(nw->a, nw->b, mid, r);
                    break;
                }else{
                    cur = cur->right, l = mid, nw->l = mid;
                }
            }else{
                swap(cur, nw);
                if(!cur->left){
                    cur->left = new node(nw->a, nw->b, l, mid);
                    break;
                }else{
                    cur = cur->left, r = mid, nw->r = mid;
                }
            }
        }
    }
    void _add_segment(node *cur, node *nw, T l, T r){
        while(true){
            const T mid = (l + r) / 2;
            if(cur->f(nw->l) <= nw->tf(nw->l) && cur->f(nw->r - 1) <= nw->tf(nw->r - 1)){
                break;
            }
            if(cur->tf(cur->l) >= nw->f(cur->l) && cur->tf(cur->r - 1) >= nw->f(cur->r - 1)){
                swap(cur, nw);
                break;
            }
            if(nw->r <= mid){
                if(!cur->left){
                    cur->left = new node(nw->a, nw->b, nw->l, nw->r);
                    break;
                }else{
                    cur = cur->left, r = mid;
                }
            }else if(mid <= nw->l){
                if(!cur->right){
                    cur->right = new node(nw->a, nw->b, nw->l, nw->r);
                    break;
                }else{
                    cur = cur->right, l = mid;
                }
            }else{
                bool use = false;
                node kp(nw->a, nw->b, nw->l, nw->r);
                if(!cur->left){
                    cur->left = new node(nw->a, nw->b, nw->l, mid);
                }else{
                    use = true, nw->r = mid;
                    _add_segment(cur->left, nw, l, mid);
                }
                if(!cur->right){
                    cur->right = new node(kp.a, kp.b, mid, kp.r);
                }else{
                    if(use) nw = new node(kp);
                    nw->l = mid;
                    _add_segment(cur->right, nw, mid, r);
                }
                break;
            }
        }
    }
    T query(node *cur, const T k, T l, T r) const {
        T ans = numeric_limits<T>::max();
        while(cur){
            ans = min(ans, cur->f(k));
            const T mid = (l + r) / 2;
            if(k < mid){
                cur = cur->left, r = mid;
            }else{
                cur = cur->right, l = mid;
            }
        }
        return ans;
    }
    void clear(node *cur){
        if(cur->left) clear(cur->left);
        if(cur->right) clear(cur->right);
        delete cur;
    }
    T lpos, rpos;
    node *root;
public:
    CHT(const T _lpos=-MX, const T _rpos=MX)
        : lpos(_lpos), rpos(_rpos),
            root(new node(0, numeric_limits<T>::max(), lpos, rpos)){
        assert(lpos < rpos);
    }
    // ~CHT(){ clear(root); }
    // f(x) = a * x + b 
    void add_line(const T a, const T b){
        node *nw = new node(a, b, lpos, rpos);
        return _add_line(root, nw, lpos, rpos);
    }
    // f(x) = a * x + b (x  [l, r)) 
    void add_segment(const T a, const T b, const T l, const T r){
        assert(l < r);
        node *nw = new node(a, b, l, r);
        return _add_segment(root, nw, lpos, rpos);
    }
    // x = k 
    T query(const T k) const {
        return query(root, k, lpos, rpos);
    }
};

CHT<ll> d[MX];
vl ans;
vi to[MX];
vi vs[MX];
vi A, B;
void dfs(int v, int p=-1) {
  int c = -1;
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,v);
    if (c == -1 || sz(vs[c]) < sz(vs[u])) c = u;
  }
  if (c != -1) {
    swap(vs[v],vs[c]);
    d[v] = d[c];
    for (int u : to[v]) {
      if (u == p || u == c) continue;
      for (int x : vs[u]) {
        vs[v].pb(x);
        d[v].add_line(B[x],ans[x]);
      }
    }
    ans[v] = d[v].query(A[v]);
  } else {
    ans[v] = 0;
  }
  vs[v].pb(v);
  d[v].add_line(B[v],ans[v]);
}

int main() {
  int n;
  scanf("%d",&n);
  ans = vl(n);
  A = B = vi(n);
  cin>>A>>B;
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  dfs(0);
  cout<<ans<<endl;
  return 0;
}