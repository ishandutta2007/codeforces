#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
// const long long MOD=1e9+7;
const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(x%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

template<typename Monoid,typename OperatorMonoid>
struct LazySegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    typedef function<Monoid(Monoid,OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    int n,hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):
                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        dat.assign(n<<1,id0);
        laz.assign(n<<1,id1);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    inline Monoid reflect(int k){
        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n),thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a),recalc(b);
    }
    void set_val(int k,Monoid x){
        thrust(k+=n);
        dat[k]=x,laz[k]=id1;
        recalc(k);
    }
    Monoid query(int a,int b){
        if (a>=b) return id0;
        thrust(a+=n),thrust(b+=n-1);
        Monoid vl=id0,vr=id0;
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,reflect(l++));
            if (r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
    Monoid operator[](int i){return query(i,i+1);}
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    vector<mint> P(n),prod(n+1,1);
    for (int i=0;i<n;++i){
        int p; cin >> p;
        P[i]=(mint)100/p;
    }
    for (int i=n-1;i>=0;--i) prod[i]=prod[i+1]*P[i];
    set<int> check;
    check.emplace(0);
    auto f=[](mint a,mint b){return a+b;};
    auto g=[](mint a,mint b){return a*b;};
    LazySegmentTree<mint,mint> seg(n,f,g,g,0,1);
    for (int i=0;i<n;++i) seg.set_val(i,prod[i]);
    for (;q--;){
        int u; cin >> u; --u;
        int pre=-*check.upper_bound(-u);
        if (check.count(-u)){
            seg.update(pre,u,seg[u]);
            check.erase(-u);
        } else {
            seg.update(pre,u,(mint)1/seg[u]);
            check.emplace(-u);
        }
        cout << seg.query(0,n) << '\n';
    }
}