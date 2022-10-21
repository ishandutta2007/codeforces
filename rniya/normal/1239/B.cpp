#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
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
    int n; string S; cin >> n >> S;

    vector<int> sum(n+1,0);
    for (int i=0;i<n;++i) sum[i+1]=sum[i]+(S[i]=='('?1:-1);
    if (sum[n]!=0){
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }

    string K="()";
    int Min=*min_element(sum.begin(),sum.end());
    int ans=0,l,r;
    auto calc=[&](int delta,int sign){
        vector<vector<int>> dp(n+1,vector<int>(3,-INF))
                            ,pre(n+1,vector<int>(3,-1));
        dp[0][0]=0;

        for (int i=0;i<n;++i){
            if (sum[i+1]>=Min+delta){
                int add=sum[i+1]==Min+delta;
                if (chmax(dp[i+1][0],dp[i][0]+add)) pre[i+1][0]=0;
                if (S[i]==K[sign]&&chmax(dp[i+1][2],dp[i][1]+add)) pre[i+1][2]=1;
                if (chmax(dp[i+1][2],dp[i][2]+add)) pre[i+1][2]=2;
            }
            if (sum[i+1]+(sign?-2:2)>=Min+delta){
                int add=sum[i+1]+(sign?-2:2)==Min+delta;
                if (S[i]==K[sign^1]&&chmax(dp[i+1][1],dp[i][0]+add)) pre[i+1][1]=0;
                if (chmax(dp[i+1][1],dp[i][1]+add)) pre[i+1][1]=1;
            }
        }

        if (chmax(ans,dp[n][0])) l=1,r=1;
        if (chmax(ans,dp[n][2])){
            for (int i=n,now=2;i>0;--i){
                if (now==2&&pre[i][now]==1) r=i;
                if (now==1&&pre[i][now]==0) l=i;
                now=pre[i][now];
            }
        }
    };

    for (int i=-2;i<=2;++i){
        for (int j=0;j<2;++j){
            calc(i,j);
        }
    }
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
}