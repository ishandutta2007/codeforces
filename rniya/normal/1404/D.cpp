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

void solve_F(int n){
    cout << "First" << endl;
    for (int i=0;i<2;++i){
        for (int j=1;j<=n;++j){
            cout << j << (i==1&&j==n?"":" ");
        }
    }
    cout << endl;
}

void solve_S(int n){
    cout << "Second" << endl;
    vector<int> p(2*n);
    for (int i=0;i<2*n;++i) cin >> p[i];

    vector<vector<int>> P(n),G(2*n);
    for (int i=0;i<2*n;++i){
        P[--p[i]].emplace_back(i);
    }
    for (int i=0;i<n;++i){
        G[P[i][0]].emplace_back(P[i][1]);
        G[P[i][1]].emplace_back(P[i][0]);
        G[i].emplace_back(i+n);
        G[i+n].emplace_back(i);
    }

    vector<int> check(2*n,0),ans(n);
    auto dfs=[&](auto self,int v,int f)->void{
        check[v]=1;
        if (!(f&1)) ans[p[v]]=v+1;
        for (int u:G[v]){
            if (check[u]) continue;
            self(self,u,f^1);
        }
    };
    for (int i=0;i<2*n;++i){
        if (check[i]) continue;
        dfs(dfs,i,0);
    }

    ll sum=accumulate(ans.begin(),ans.end(),0LL);
    if (sum%(2*n)!=0){
        for (int i=0;i<n;++i){
            ans[i]=P[i][0]+P[i][1]+2-ans[i];
        }
    }

    for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?"":" ");
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n&1) solve_S(n);
    else solve_F(n);
    int res; cin >> res;
    assert(res==0);
}