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

void solve(){
    int n,k; cin >> n >> k;
    struct minion{
        int a,b,id;
        minion(int a,int b,int id):a(a),b(b),id(id){}
        const bool operator<(const minion &other){
            return b<other.b;
        }
    };
    vector<minion> M;
    for (int i=0;i<n;++i){
        int a,b; cin >> a >> b;
        M.emplace_back(a,b,i);
    }

    sort(ALL(M));
    vector<vector<int>> dp(n+1,vector<int>(k+1,-INF));
    vector<vector<int>> pre(n+1,vector<int>(k+1));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        int a=M[i].a,b=M[i].b;
        for (int j=0;j<=k;++j){
            if (chmax(dp[i+1][j],dp[i][j]+b*(k-1))){
                pre[i+1][j]=0;
            }
            if (j+1<=k&&chmax(dp[i+1][j+1],dp[i][j]+a+b*j)){
                pre[i+1][j+1]=1;
            }
        }
    }

    vector<int> summon(n,0),ans;
    for (int i=n-1,j=k;i>=0;--i){
        summon[M[i].id]=pre[i+1][j];
        if (pre[i+1][j]) ans.emplace_back(M[i].id+1);
        j-=pre[i+1][j];
    }
    reverse(ALL(ans));

    int last=ans.back(); ans.pop_back();
    for (int i=0;i<n;++i){
        if (!summon[i]){
            ans.emplace_back(i+1);
            ans.emplace_back(-(i+1));
        }
    }
    ans.emplace_back(last);

    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for (;T--;){
        solve();
    }
}