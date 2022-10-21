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

const int MAX_LOG=20;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<pair<int,int>>> G(n);
    for (int i=0;i<n-1;++i){
        int x,y,v; cin >> x >> y >> v; --x,--y;
        G[x].emplace_back(y,v);
        G[y].emplace_back(x,v);
    }
    auto dfs=[&](auto self,int v,int p,vector<ll> &d)->void{
        if (p<0) d[v]=0;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            d[u]=d[v]+e.second;
            self(self,u,v,d);
        }
    };
    vector<ll> ds(n),dt(n);
    dfs(dfs,0,-1,ds);
    int s,t; ll Max=0;
    for (int v=0;v<n;++v){
        if (Max<ds[v]){
            Max=ds[v];
            s=v;
        }
    }
    dfs(dfs,s,-1,ds);
    Max=0;
    for (int v=0;v<n;++v){
        if (Max<ds[v]){
            Max=ds[v];
            t=v;
        }
    }
    dfs(dfs,t,-1,dt);

    int r; ll Min=IINF;
    for (int v=0;v<n;++v){
        ds[v]=max(ds[v],dt[v]);
        if (ds[v]<Min){
            Min=ds[v];
            r=v;
        }
    }
    for (int v=0;v<n;++v) ds[v]-=Min;

    vector<vector<int>> par(n,vector<int>(MAX_LOG,-1));
    auto dfs1=[&](auto self,int v,int p)->void{
        par[v][0]=p;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            self(self,u,v);
        }
    };
    dfs1(dfs1,r,-1);
    for (int j=0;j<MAX_LOG-1;++j){
        for (int i=0;i<n;++i){
            if (~par[i][j]){
                par[i][j+1]=par[par[i][j]][j];
            }
        }
    }

    int ans;
    vector<int> imos(n);
    auto dfs2=[&](auto self,int v,int p)->void{
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            self(self,u,v);
            imos[v]+=imos[u];
        }
        ans=max(ans,imos[v]);
    };

    auto solve=[&](ll l){
        for (int i=0;i<n;++i) imos[i]=0;
        for (int v=0;v<n;++v){
            int cur=v;
            for (int i=MAX_LOG-1;i>=0;--i){
                if (par[cur][i]<0) continue;
                if (ds[v]-ds[par[cur][i]]<=l){
                    cur=par[cur][i];
                }
            }
            ++imos[v];
            if (~par[cur][0]) --imos[par[cur][0]];
        }
        ans=0;
        dfs2(dfs2,r,-1);
        return ans;
    };

    int q; cin >> q;
    for (;q--;){
        ll l; cin >> l;
        cout << solve(l) << '\n';
    }
}