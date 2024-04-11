#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=600005,INF=1<<30;

// BIT   

// from: https://gist.github.com/yosupo06/ddd51afb727600fd95d9d8ad6c3c80c9
// (based on AtCoder STL)

#include <algorithm>
#include <array>
#ifdef _MSC_VER
#include <intrin.h>
#endif
namespace atcoder {
    namespace internal {
        int ceil_pow2(int n) {
            int x = 0;
            while ((1U << x) < (unsigned int)(n)) x++;
            return x;
        }
        int bsf(unsigned int n) {
#ifdef _MSC_VER
            unsigned long index;
            _BitScanForward(&index, n);
            return index;
#else
            return __builtin_ctz(n);
#endif
        }
    }  // namespace internal
    
}  // namespace atcoder

#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {
    
    namespace internal {
        
#ifndef _MSC_VER
        template <class T>
        using is_signed_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value ||
        std::is_same<T, __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int128 =
        typename std::conditional<std::is_same<T, __uint128_t>::value ||
        std::is_same<T, unsigned __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using make_unsigned_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value,
        __uint128_t,
        unsigned __int128>;
        
        template <class T>
        using is_integral = typename std::conditional<std::is_integral<T>::value ||
        is_signed_int128<T>::value ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                         std::is_signed<T>::value) ||
        is_signed_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<(is_integral<T>::value &&
                                   std::is_unsigned<T>::value) ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<
        is_signed_int128<T>::value,
        make_unsigned_int128<T>,
        typename std::conditional<std::is_signed<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type>::type;
        
#else
        
        template <class T> using is_integral = typename std::is_integral<T>;
        
        template <class T>
        using is_signed_int =
        typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<is_integral<T>::value &&
        std::is_unsigned<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<is_signed_int<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type;
        
#endif
        
        template <class T>
        using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
        
        template <class T>
        using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
        
        template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
        
    }  // namespace internal
    
}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {
    
    template <class T> struct fenwick_tree {
        using U = internal::to_unsigned_t<T>;
        
    public:
        fenwick_tree() : _n(0) {}
        fenwick_tree(int n) : _n(n), data(n) {}
        
        void add(int p, T x) {
            assert(0 <= p && p < _n);
            p++;
            while (p <= _n) {
                data[p - 1] += U(x);
                p += p & -p;
            }
        }
        
        T sum(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            return sum(r) - sum(l);
        }
        
    private:
        int _n;
        std::vector<U> data;
        
        U sum(int r) {
            U s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }
    };
    
}  // namespace atcoder


#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {
    
    template <class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*composition)(F, F),
    F (*id)()>
    struct lazy_segtree {
    public:
        lazy_segtree() : lazy_segtree(0) {}
        lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
        lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::ceil_pow2(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            lz = std::vector<F>(size, id());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }
        
        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        
        S get(int p) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }
        
        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return e();
            
            l += size;
            r += size;
            
            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push(r >> i);
            }
            
            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            
            return op(sml, smr);
        }
        
        S all_prod() { return d[1]; }
        
        void apply(int p, F f) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        void apply(int l, int r, F f) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return;
            
            l += size;
            r += size;
            
            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }
            
            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }
            
            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }
        
        template <bool (*g)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return g(x); });
        }
        template <class G> int max_right(int l, G g) {
            assert(0 <= l && l <= _n);
            assert(g(e()));
            if (l == _n) return _n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = (2 * l);
                        if (g(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        
        template <bool (*g)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return g(x); });
        }
        template <class G> int min_left(int r, G g) {
            assert(0 <= r && r <= _n);
            assert(g(e()));
            if (r == 0) return 0;
            r += size;
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(op(d[r], sm))) {
                    while (r < size) {
                        push(r);
                        r = (2 * r + 1);
                        if (g(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }
        
    private:
        int _n, size, log;
        std::vector<S> d;
        std::vector<F> lz;
        
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
        void all_apply(int k, F f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }
        void push(int k) {
            all_apply(2 * k, lz[k]);
            all_apply(2 * k + 1, lz[k]);
            lz[k] = id();
        }
    };
    
}  // namespace atcoder

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {
    
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {
    public:
        segtree() : segtree(0) {}
        segtree(int n) : segtree(std::vector<S>(n, e())) {}
        segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::ceil_pow2(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }
        
        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        
        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }
        
        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;
            
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        
        S all_prod() { return d[1]; }
        
        template <bool (*f)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return f(x); });
        }
        template <class F> int max_right(int l, F f) {
            assert(0 <= l && l <= _n);
            assert(f(e()));
            if (l == _n) return _n;
            l += size;
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!f(op(sm, d[l]))) {
                    while (l < size) {
                        l = (2 * l);
                        if (f(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        
        template <bool (*f)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return f(x); });
        }
        template <class F> int min_left(int r, F f) {
            assert(0 <= r && r <= _n);
            assert(f(e()));
            if (r == 0) return 0;
            r += size;
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!f(op(d[r], sm))) {
                    while (r < size) {
                        r = (2 * r + 1);
                        if (f(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }
        
    private:
        int _n, size, log;
        std::vector<S> d;
        
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    };
    
}  // namespace atcoder

struct T{
    bool alive;
    int almi;
    int alma;
    int opmi;
    int opma;
};

using E=int;

T f(T a,T b){
    if(a.alive){
        if(b.alive){
            return {true,min(a.almi,b.almi),max(a.alma,b.alma),min(a.opmi,b.opmi),max(a.opma,b.opma)};
        }else{
            return {true,min(a.almi,b.almi),max(a.alma,b.alma),a.opmi,a.opma};
        }
    }else{
        if(b.alive){
            return {true,min(a.almi,b.almi),max(a.alma,b.alma),b.opmi,b.opma};
        }else{
            return {false,min(a.almi,b.almi),max(a.alma,b.alma),INF,-INF};
        }
    }
}

T g(E a,T b){
    if(a==-1) return b;
    else if(a==0){
        return {false,b.almi,b.alma,INF,-INF};
    }else{
        return {true,b.almi,b.alma,b.almi,b.alma};
    }
}

E h(E a,E b){
    if(a==-1) return b;
    return a;
}

T ti(){
    return {false,INF,-INF,INF,-INF};
}

E ei(){
    return -1;
}

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

struct edge{
    int from;
    int to;
    int cost;
};

vector<int> G[MAX];
int X[MAX];

int t=0;
int tin[MAX],dic[MAX];
void DFS(int u){
    tin[u]=t;
    dic[t]=u;
    t++;
    
    for(int to:G[u]){
        DFS(to);
    }
}

const int MAX_LOG=20;
int parr[MAX_LOG][MAX],depth[MAX];

void init(int u,int N){
    for(int i=0;i<N;i++){
        depth[i]=INF;
        for(int j=0;j<20;j++){
            parr[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int to:G[a]){
            if(chmin(depth[to],depth[a]+1)){
                parr[0][to]=a;
                Q.push(to);
            }
        }
    }
    
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(parr[k][i]<0) parr[k+1][i]=-1;
            else parr[k+1][i]=parr[k][parr[k][i]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth[v]-depth[u])>>i)&1) v=parr[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(parr[i][u]!=parr[i][v]){
            u = parr[i][u];
            v = parr[i][v];
        }
    }
    return parr[0][u];
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    vector<edge> EE(N-1);
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        EE[i]={a,b,c};
    }
    sort(all(EE),[](auto a,auto b){
        return a.cost<b.cost;
    });
    
    UF uf;uf.init(2*N);
    int sz=N;
    for(auto e:EE){
        X[sz]=e.cost;
        int a=uf.root(e.from),b=uf.root(e.to);
        G[sz].push_back(a);
        G[sz].push_back(b);
        uf.unite(sz,a);
        uf.unite(sz,b);
        sz++;
    }
    
    DFS(sz-1);
    
    vector<T> def(N);
    for(int i=0;i<N;i++){
        def[i].alive=false;
        def[i].almi=tin[i];
        def[i].alma=tin[i];
        def[i].opmi=INF;
        def[i].opma=-INF;
    }
    
    atcoder::lazy_segtree<T,f,ti,E,g,h,ei> seg(def);
    
    init(sz-1,sz);
    
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int l,r;cin>>l>>r;l--;
            seg.apply(l,r,1);
        }
        if(t==2){
            int l,r;cin>>l>>r;l--;
            seg.apply(l,r,0);
        }
        if(t==3){
            int x;cin>>x;x--;
            auto res=seg.all_prod();
            int mi=res.opmi,ma=res.opma;
            int ans=-1;
            if(mi!=INF&&dic[mi]!=x){
                int a=lca(dic[mi],x);
                chmax(ans,X[a]);
            }
            if(ma!=-INF&&dic[ma]!=x){
                int a=lca(dic[ma],x);
                chmax(ans,X[a]);
            }
            cout<<ans<<"\n";
        }
    }
}