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
    cout << '(' << p.first << ',' << p.second << ')';
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

template<class K,size_t N>
struct SquareMatrix{
    array<array<K,N>,N> dat;
    SquareMatrix(){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                dat[i][j]=K();
    }
    size_t size() const{return N;}
    array<K,N> &operator[](size_t i){return dat[i];}
    const array<K,N> &operator[](size_t i) const{return dat[i];}
    static SquareMatrix I(){
        SquareMatrix res;
        for (size_t i=0;i<N;++i) res[i][i]=K(1);
        return res;
    }
    SquareMatrix &operator+=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]+=B[i][j];
        return (*this);
    }
    SquareMatrix operator+(const SquareMatrix &B) const{
        return SquareMatrix(*this)+=B;
    }
    SquareMatrix &operator-=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]-=B[i][j];
        return (*this);
    }
    SquareMatrix operator-(const SquareMatrix &B) const{
        return SquareMatrix(*this)-=B;
    }
    SquareMatrix &operator*=(const SquareMatrix &B){
        SquareMatrix res;
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                for (size_t k=0;k<N;++k)
                    res[i][j]+=(*this)[i][k]*B[k][j];
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator*(const SquareMatrix &B) const{
        return SquareMatrix(*this)*=B;
    }
    SquareMatrix &operator^=(long long k){
        SquareMatrix res=I();
        while(k){
            if (k&1LL) res*=*this;
            *this*=*this; k>>=1LL;
        }
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator^(long long k) const{
        return SquareMatrix(*this)^=k;
    }
};

using SM=SquareMatrix<mint,2>;

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    // most left position that meets condition "check"
    template<typename C>
    int find(int a,int b,const C &check,int k,int l,int r){
        if (!check(dat[k])||r<=a||b<=l) return -1;
        if (l+1==r) return k-n;
        int vl=find(a,b,check,k<<1|0,l,(l+r)>>1);
        if (~vl) return vl;
        return find(a,b,check,k<<1|1,(l+r)>>1,r);
    }
    template<typename C>
    int find(int a,int b,const C &check){
        return find(a,b,check,1,0,n);
    }
    Monoid operator[](int i){return dat[i+n];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    string S; cin >> S;
    SM id=SM::I();
    auto f=[](SM a,SM b){return a*b;};
    vector<int> cnt(100,0);
    for (int i=0;i<10;++i){
        for (int j=0;j<10;++j){
            ++cnt[i+j];
        }
    }
    auto g=[&](int i){
        SM res;
        res[0][0]=(S[i]-'0')+1; res[1][0]=1;
        if (i==n-1) return res;
        int two=(S[i]-'0')*10+(S[i+1]-'0');
        if (S[i]!='0') res[0][1]=cnt[two];
        return res;
    };
    SegmentTree<SM> seg(n,f,SM::I());
    for (int i=0;i<n;++i) seg.update(i,g(i));
    for (;m--;){
        int x; char d; cin >> x >> d; --x;
        S[x]=d;
        seg.update(x,g(x));
        if (x-1>=0) seg.update(x-1,g(x-1));
        auto M=seg.query(0,n);
        cout << M[0][0] << '\n';
    }
}