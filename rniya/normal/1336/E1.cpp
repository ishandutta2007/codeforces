#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
// const long long MOD=1000000007;
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

template<uint32_t mod> class modint{
    using i64=int64_t;
    using u32=uint32_t;
    using u64=uint64_t;
public:
    u32 v;
    constexpr modint(const i64 x=0) noexcept :v(x<0?mod-1-(-(x+1)%mod):x%mod){}
    constexpr u32 &value() noexcept {return v;}
    constexpr const u32 &value() const noexcept {return v;}
    constexpr modint operator+(const modint &rhs) const noexcept {return modint(*this)+=rhs;}
    constexpr modint operator-(const modint &rhs) const noexcept {return modint(*this)-=rhs;}
    constexpr modint operator*(const modint &rhs) const noexcept {return modint(*this)*=rhs;}
    constexpr modint operator/(const modint &rhs) const noexcept {return modint(*this)/=rhs;}
    constexpr modint &operator+=(const modint &rhs) noexcept {
        v+=rhs.v;
        if (v>=mod) v-=mod;
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept {
        if (v<rhs.v) v+=mod;
        v-=rhs.v;
        return *this;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept {
        v=(u64)v*rhs.v%mod;
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) noexcept {
        return *this*=rhs.pow(mod-2);
    }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this),res(1);
        while (exp>0){
            if (exp&1) res*=self;
            self*=self; exp>>=1;
        }
        return res;
    }
    constexpr modint &operator++() noexcept {if (++v==mod) v=0; return *this;}
    constexpr modint &operator--() noexcept {if (v==0) v=mod; return --v,*this;}
    constexpr modint operator++(int) noexcept {modint t=*this; return ++*this,t;}
    constexpr modint operator--(int) noexcept {modint t=*this; return --*this,t;}
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept {return modint(x)+y;}
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept {return modint(x)-y;}
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept {return modint(x)*y;}
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept {return modint(x)/y;}
    constexpr bool operator==(const modint &rhs) const noexcept {return v==rhs.v;}
    constexpr bool operator!=(const modint &rhs) const noexcept {return v!=rhs.v;}
    constexpr bool operator!() const noexcept {return !v;}
    friend istream &operator>>(istream &s,modint &rhs) noexcept {
        i64 v; rhs=modint{(s>>v,v)}; return s;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept {
        return s<<rhs.v;
    }
};

template<typename T>
void fwt(vector<T> &f){
    int n=f.size();
    for (int i=1;i<n;i<<=1){
        for (int j=0;j<n;++j){
            if (!(j&i)){
                T x=f[j],y=f[j|i];
                f[j]=x+y,f[j|i]=x-y;
            }
        }
    }
}
template<typename T>
void ifwt(vector<T> &f){
    int n=f.size();
    for (int i=1;i<n;i<<=1){
        for (int j=0;j<n;++j){
            if (!(j&i)){
                T x=f[j],y=f[j|i];
                f[j]=(x+y)*499122177,f[j|i]=(x-y)*499122177;
            }
        }
    }
}

using mint=modint<MOD>;
const int MAX_M=18,HALF=1<<MAX_M;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    vector<ll> bases;
    for (int i=0;i<n;++i){
        ll a; cin >> a;
        for (ll base:bases) a=min(a,a^base);
        if (a>0) bases.emplace_back(a);
    }

    vector<ll> a,b;
    for (ll base:bases){
        if (base<HALF) a.emplace_back(base);
        else b.emplace_back(base);
    }
    int N=a.size(),M=b.size();
    vector<vector<mint>> f(MAX_M,vector<mint>(HALF,0))
                        ,g(MAX_M,vector<mint>(HALF,0));

    for (int mask=0;mask<(1<<N);++mask){
        ll XOR=0;
        for (int i=0;i<N;++i){
            if (mask&1<<i){
                XOR^=a[i];
            }
        }
        for (int i=0;i<MAX_M;++i) ++f[i][XOR];
    }
    for (int mask=0;mask<(1<<M);++mask){
        ll XOR=0;
        for (int i=0;i<M;++i){
            if (mask&1<<i){
                XOR^=b[i];
            }
        }
        int flag=0;
        for (int i=MAX_M;i<2*MAX_M;++i) flag+=((XOR>>i)&1);
        ++g[flag][XOR&(HALF-1)];
    }
    vector<int> flags(HALF);
    for (int mask=0;mask<HALF;++mask) flags[mask]=__builtin_popcount(mask);

    vector<mint> ans(2*MAX_M+1,0);
    for (int i=0;i<MAX_M;++i){
        fwt(f[i]); fwt(g[i]);
        for (int j=0;j<HALF;++j) f[i][j]*=g[i][j];
        ifwt(f[i]);
        for (int j=0;j<HALF;++j) ans[flags[j]+i]+=f[i][j];
    }

    mint POW=((mint)2).pow(n-bases.size());
    for (int i=0;i<=m;++i) cout << ans[i]*POW << (i==m?'\n':' ');
}