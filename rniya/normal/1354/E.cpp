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

const int MAX_N=5010;

vector<int> comp[MAX_N][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> c(3); cin >> c;
    vector<vector<int>> G(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int ok=1;
    vector<int> color(n,-1),root(n);
    auto dfs=[&](auto self,int v,int r)->void{
        root[v]=r;
        for (int u:G[v]){
            if (~color[u]){
                if (color[u]==color[v]) ok=0;
                continue;
            }
            color[u]=color[v]^1;
            self(self,u,r);
        }
    };

    for (int i=0;i<n;++i){
        if (~color[i]) continue;
        color[i]=0;
        dfs(dfs,i,i);
    }

    if (!ok){cout << "NO" << '\n'; return 0;}

    for (int i=0;i<n;++i) comp[root[i]][color[i]].emplace_back(i);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    dp[0][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<=n;++j){
            for (int k=0;k<2;++k){
                if (dp[i][j]<0) continue;
                int s=comp[i][k].size();
                if (j+s<=n) dp[i+1][j+s]=s;
            }
        }
    }

    if (dp[n][c[1]]<0){cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';

    vector<char> ans(n,'0');
    for (int i=n-1,j=c[1];i>=0;--i){
        int s=dp[i+1][j];
        for (int k=0;k<2;++k){
            if (comp[i][k].size()==s){
                for (int v:comp[i][k]) ans[v]='2';
                break;
            }
        }
        j-=s;
    }

    for (int i=0;i<n;++i){
        if (ans[i]!='0') continue;
        if (c[0]>0){
            ans[i]='1'; --c[0];
        } else {
            ans[i]='3'; --c[1];
        }
    }

    for (int i=0;i<n;++i) cout << ans[i];
    cout << '\n';
}