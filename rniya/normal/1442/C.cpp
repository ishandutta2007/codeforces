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

using T=tuple<int,int,int>;
using TT=tuple<int,int,int,int>;
using mint=modint<MOD>;
const int MAX_N=200010,MAX_LOG=24;
const pair<int,int> PINF={INF,INF};

pair<int,int> dp[MAX_N][MAX_LOG][2];
vector<int> G[MAX_N][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u][0].emplace_back(v);
        G[v][1].emplace_back(u);
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<MAX_LOG;++j){
            for (int k=0;k<2;++k){
                dp[i][j][k]=PINF;
            }
        }
    }

    vector<priority_queue<T,vector<T>,greater<T>>> pq(MAX_LOG-1);
    priority_queue<TT,vector<TT>,greater<TT>> pq2;
    dp[0][0][0]={0,0}; pq[0].emplace(dp[0][0][0].second,0,0);
    for (int i=0;i<MAX_LOG-1;++i){
        while(!pq[i].empty()){
            auto t=pq[i].top(); pq[i].pop();
            int v=get<1>(t),d=get<2>(t),cur=get<0>(t);
            if (dp[v][i][d].second<cur) continue;
            for (int u:G[v][d]){
                if (cur+1<dp[u][i][d].second){
                    dp[u][i][d]={dp[v][i][d].first,dp[v][i][d].second+1};
                    pq[i].emplace(dp[u][i][d].second,u,d);
                }
            }
            for (int u:G[v][d^1]){
                if (i<MAX_LOG-2){
                    if (cur+1<dp[u][i+1][d^1].second){
                        dp[u][i+1][d^1]={dp[v][i][d].first+1,dp[v][i][d].second+1};
                        pq[i+1].emplace(dp[u][i+1][d^1].second,u,d^1);
                    }
                } else {
                    auto cand=dp[u][i+1][d^1];
                    if (i+1<cand.first||(i+1==cand.first&&cur+1<cand.second)){
                        dp[u][i+1][d^1]={dp[v][i][d].first+1,dp[v][i][d].second+1};
                        pq2.emplace(dp[u][i+1][d^1].first,dp[u][i+1][d^1].second,u,d^1);
                    }
                }
            }
        }
    }
    while(!pq2.empty()){
        auto t=pq2.top(); pq2.pop();
        int v=get<2>(t),d=get<3>(t),cur1=get<0>(t),cur2=get<1>(t);
        if (dp[v][MAX_LOG-1][d]<pair<int,int>{cur1,cur2}) continue;
        for (int u:G[v][d]){
            pair<int,int> nxt={cur1,cur2+1};
            if (nxt<dp[u][MAX_LOG-1][d]){
                dp[u][MAX_LOG-1][d]=nxt;
                pq2.emplace(dp[u][MAX_LOG-1][d].first,dp[u][MAX_LOG-1][d].second,u,d);
            }
        }
        for (int u:G[v][d^1]){
            pair<int,int> nxt={cur1+1,cur2+1};
            if (nxt<dp[u][MAX_LOG-1][d^1]){
                dp[u][MAX_LOG-1][d^1]=nxt;
                pq2.emplace(dp[u][MAX_LOG-1][d^1].first,dp[u][MAX_LOG-1][d^1].second,u,d^1);
            }
        }
    }

    vector<mint> POW(MAX_N,0);
    POW[1]=1;
    for (int i=1;i<MAX_N-1;++i) POW[i+1]=POW[i]*2;
    for (int i=0;i<MAX_N-1;++i) POW[i+1]+=POW[i];
    vector<int> power(MAX_LOG+2,0);
    power[1]=1;
    for (int i=1;i<MAX_LOG+1;++i) power[i+1]=power[i]*2;
    for (int i=0;i<MAX_LOG+1;++i) power[i+1]+=power[i];

    int ans=INF;
    for (int i=0;i<MAX_LOG-1;++i){
        for (int j=0;j<2;++j){
            if (dp[n-1][i][j]==PINF) continue;
            int cnt=power[i]+dp[n-1][i][j].second;
            chmin(ans,cnt);
        }
    }
    if (ans!=INF){cout << ans << '\n'; return 0;}

    pair<int,int> pans=dp[n-1][MAX_LOG-1][0];
    if (dp[n-1][MAX_LOG-1][1]<pans) pans=dp[n-1][MAX_LOG-1][1];
    mint res=POW[pans.first]+pans.second;
    cout << res << '\n';
}