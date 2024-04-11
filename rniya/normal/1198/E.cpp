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

template<typename T,bool directed>
struct Dinic{
    struct edge{
        int to,rev; T cap;
        edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<int> level,iter;
    Dinic(int n):G(n),level(n),iter(n){}
    int add_edge(int from,int to,T cap){
        G[from].emplace_back(to,cap,G[to].size());
        G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
        return G[to].back().rev;
    }
    void bfs(int s){
        fill(level.begin(),level.end(),-1);
        queue<int> que;
        level[s]=0;
        que.emplace(s);
        while(!que.empty()){
            int v=que.front(); que.pop();
            for (auto &e:G[v]){
                if (e.cap>0&&level[e.to]<0){
                    level[e.to]=level[v]+1;
                    que.emplace(e.to);
                }
            }
        }
    }
    T dfs(int v,int t,T f){
        if (v==t) return f;
        for (int &i=iter[v];i<G[v].size();++i){
            edge &e=G[v][i];
            if (e.cap>0&&level[v]<level[e.to]){
                T d=dfs(e.to,t,min(f,e.cap));
                if (d==0) continue;
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s,int t,T lim){
        T flow=0;
        while(1){
            bfs(s);
            if (level[t]<0||lim==0) break;
            fill(iter.begin(),iter.end(),0);
            while(1){
                T f=dfs(s,t,lim);
                if (f==0) break;
                flow+=f;
                lim-=f;
            }
        }
        return flow;
    }
    T max_flow(int s,int t){
        return max_flow(s,t,numeric_limits<T>::max()/2);
    }
};

map<int,int> compress(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map<int,int> res;
    for (int i=0;i<v.size();++i) res[v[i]]=i;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> X(m,vector<int>(2)),Y(m,vector<int>(2));
    vector<int> cx,cy;
    for (int i=0;i<m;++i){
        for (int j=0;j<2;++j){
            cin >> X[i][j] >> Y[i][j];
            if (!j) --X[i][j],--Y[i][j];
            cx.emplace_back(X[i][j]);
            cy.emplace_back(Y[i][j]);
        }
    }
    cx.emplace_back(n); cy.emplace_back(n);

    map<int,int> mx=compress(cx),my=compress(cy);
    int N=mx.size(),M=my.size();
    vector<int> Xs,Ys;
    for (auto p:mx) Xs.emplace_back(p.first);
    for (auto p:my) Ys.emplace_back(p.first);
    vector<vector<int>> imos(N+1,vector<int>(M+1,0));
    for (int i=0;i<m;++i){
        for (int j=0;j<2;++j) X[i][j]=mx[X[i][j]],Y[i][j]=my[Y[i][j]];
        ++imos[X[i][0]][Y[i][0]]; ++imos[X[i][1]][Y[i][1]];
        --imos[X[i][1]][Y[i][0]]; --imos[X[i][0]][Y[i][1]];
    }
    for (int i=0;i<=N;++i){
        for (int j=0;j<M;++j){
            imos[i][j+1]+=imos[i][j];
        }
    }
    for (int j=0;j<=M;++j){
        for (int i=0;i<N;++i){
            imos[i+1][j]+=imos[i][j];
        }
    }

    Dinic<ll,true> D(N+M+2);
    for (int i=0;i+1<N;++i) D.add_edge(0,i+1,Xs[i+1]-Xs[i]);
    for (int i=0;i+1<M;++i) D.add_edge(N+1+i,N+M+1,Ys[i+1]-Ys[i]);
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            if (imos[i][j]){
                D.add_edge(i+1,N+1+j,IINF);
            }
        }
    }

    cout << D.max_flow(0,N+M+1) << '\n';
}