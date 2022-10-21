#include <bits/stdc++.h>
using namespace std;
// #define LOCAL
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

struct StronglyConnectedComponents{
    vector<vector<int>> G,rG,C,T;
    vector<int> vs,cmp,used;
    StronglyConnectedComponents(int n):G(n),rG(n),cmp(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int v){
        used[v]=1;
        for (int u:G[v]) if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }
    void rdfs(int v,int k){
        used[v]=1;
        cmp[v]=k;
        C[k].emplace_back(v);
        for (int u:rG[v]) if (!used[u]) rdfs(u,k);
    }
    int build(){
        int n=G.size();
        for (int i=0;i<n;++i) if (!used[i]) dfs(i);
        fill(used.begin(),used.end(),0);
        int k=0;
        for (int i=n-1;i>=0;--i){
            if (!used[vs[i]]){
                C.emplace_back(),T.emplace_back();
                rdfs(vs[i],k++);
            }
        }
        for (int v=0;v<n;++v){
            for (int u:G[v]){
                if (cmp[v]!=cmp[u]){
                    T[cmp[v]].emplace_back(cmp[u]);
                }
            }
        }
        for (int i=0;i<k;++i){
            sort(T[i].begin(),T[i].end());
            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
        }
        return k;
    }
    int operator[](int i) const{return cmp[i];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,d; cin >> n >> m >> d;

    StronglyConnectedComponents SCC(n);
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v;
        SCC.add_edge(--u,--v);
    }
    int s=SCC.build();
    vector<string> D(n);
    for (int i=0;i<n;++i) cin >> D[i];

    vector<int> V(s);
    for (int i=0;i<s;++i) V[i]=SCC.C[i][0];
    vector<vector<int>> &G=SCC.G;
    vector<vector<int>> visited(n,vector<int>(d,0)),cnt(s,vector<int>(d,0));
    vector<int> diff(n);
    auto bfs=[&](int s){
        queue<pair<int,int>> que;
        visited[s][0]=1; que.emplace(s,0);
        while(!que.empty()){
            auto p=que.front(); que.pop();
            int v=p.first,t=p.second;
            for (int u:G[v]){
                if (SCC[v]!=SCC[u]) continue;
                if (visited[u][(t+1)%d]) continue;
                visited[u][(t+1)%d]=1;
                que.emplace(u,(t+1)%d);
            }
        }
    };
    for (int i=0;i<s;++i){
        bfs(V[i]);
        for (int j=0;j<d;++j){
            for (int u:SCC.C[i]){
                int ok=0;
                for (int k=0;k<d;++k){
                    if (visited[u][k]&&D[u][(j+k)%d]=='1'){
                        ok=1;
                    }
                }
                cnt[i][j]+=ok;
            }
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<d;++j){
            if (visited[i][j]){
                diff[i]=j;
            }
        }
    }

    vector<vector<int>> dp(s+1,vector<int>(d,-INF));
    dp[SCC[0]][(d-diff[0])%d]=0;
    for (int i=0;i<s;++i){
        for (int j=0;j<d;++j) dp[i][j]+=cnt[i][j];
        for (int j=0;j<d;++j){
            for (int k=0;k<d;++k){
                if (visited[V[i]][k]){
                    dp[i][(j+k)%d]=max(dp[i][(j+k)%d],dp[i][j]);
                }
            }
        }
        for (int v:SCC.C[i]){
            for (int u:G[v]){
                if (SCC[v]==SCC[u]) continue;
                for (int j=0;j<d;++j){
                    for (int k=0;k<d;++k){
                        if (!visited[v][k]) continue;
                        int nt=(j+k+1-diff[u]+d)%d;
                        dp[SCC[u]][nt]=max(dp[SCC[u]][nt],dp[i][j]);
                    }
                }
            }
        }
        debug(dp[i]);
    }

    int ans=0;
    for (int i=0;i<s;++i){
        for (int j=0;j<d;++j){
            ans=max(ans,dp[i][j]);
        }
    }
    for (int i=0;i<s;++i){debug(cnt[i]);}
    for (int i=0;i<n;++i){debug(visited[i]);}

    cout << ans << '\n';
}