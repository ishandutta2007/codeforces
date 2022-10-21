#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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

class runtime_modint{
    using u64=uint_fast64_t;
    static u64 &mod(){
        static u64 mod_=0;
        return mod_;
    }
    public:
    u64 a;
    static void set_mod(const u64 x){mod()=x;}
    static u64 get_mod(){return mod();}
    runtime_modint(const u64 x=0):a(x%get_mod()){}
    u64 &balue() noexcept{return a;}
    const u64 &value() const noexcept{return a;}
    runtime_modint &operator+=(const runtime_modint &rhs){
        a+=rhs.a;
        if (a>=get_mod()) a-=get_mod();
        return *this;
    }
    runtime_modint operator+(const runtime_modint &rhs) const{
        return runtime_modint(*this)+=rhs;
    }
    runtime_modint &operator-=(const runtime_modint &rhs){
        if (a<rhs.a) a+=get_mod();
        a-=rhs.a;
        return *this;
    }
    runtime_modint operator-(const runtime_modint &rhs) const{
        return runtime_modint(*this)-=rhs;
    }
    runtime_modint &operator*=(const runtime_modint &rhs){
        a=a*rhs.a%get_mod();
        return *this;
    }
    runtime_modint operator*(const runtime_modint &rhs) const{
        return runtime_modint(*this)*=rhs;
    }
    runtime_modint &operator/=(runtime_modint rhs){
        u64 exp=get_mod()-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    runtime_modint operator/(const runtime_modint &rhs) const{
        return runtime_modint(*this)/=rhs;
    }
    friend runtime_modint pow(runtime_modint rhs,long long exp) noexcept{
        runtime_modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    friend ostream &operator<<(ostream &s,const runtime_modint &rhs){
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,runtime_modint &rhs){
        u64 a; rhs=runtime_modint{(s >> a,a)}; return s;
    }
};

using mint=runtime_modint;

void solve(){
    int d,m; cin >> d >> m;
    mint::set_mod(m);
    mint ans=1;
    int now=1;
    while(now<=d){
        int M=min(d,(now<<1)-1);
        ans*=(M-now+2);
        now<<=1;
    }
    cout << ans-1 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}