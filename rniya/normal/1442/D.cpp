#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
// const long long MOD=998244353;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,K; cin >> n >> K;
    vector<int> t(n);
    vector<vector<ll>> sum(n);
    for (int i=0;i<n;++i){
        cin >> t[i]; sum[i].emplace_back(0);
        for (int j=0;j<t[i];++j){
            int A; cin >> A;
            sum[i].emplace_back(sum[i].back()+A);
        }
    }

    ll ans=0;
    vector<ll> dp(K+1,-IINF); dp[0]=0;
    auto add=[&](int j,vector<ll> &dp){
        for (int i=K;i>=t[j];--i){
            dp[i]=max(dp[i],dp[i-t[j]]+sum[j].back());
        }
    };
    auto dfs=[&](auto self,int l,int r,const vector<ll> &dp)->void{
        if (r-l<=1){
            for (int i=0;i<=K;++i){
                if (K-i<sum[l].size()){
                    ans=max(ans,dp[i]+sum[l][K-i]);
                }
            }
            return;
        }

        int mid=(l+r)>>1;
        auto ndp=dp;
        for (int j=mid;j<r;++j) add(j,ndp);
        self(self,l,mid,ndp);

        ndp=dp;
        for (int j=l;j<mid;++j) add(j,ndp);
        self(self,mid,r,ndp);
    };

    dfs(dfs,0,n,dp);
    cout << ans << '\n';
}