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
    int add_vertex(){
        G.emplace_back();
        level.emplace_back();
        iter.emplace_back();
        return G.size()-1;
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

template<typename T>
struct ProjectSelectionProblem{
    int s,t;
    T sum=0;
    const T inf=numeric_limits<T>::max()/2;
    Dinic<T,true> D;
    ProjectSelectionProblem(int n):s(n),t(n+1),D(n+2){}
    void x_false_loss(int x,T z){
        D.add_edge(x,t,z);
    }
    void x_false_profit(int x,T z){
        sum+=z;
        x_true_loss(x,z);
    }
    void x_true_loss(int x,T z){
        D.add_edge(s,x,z);
    }
    void x_true_profit(int x,T z){
        sum+=z;
        x_false_loss(x,z);
    }
    void x_false_y_true_loss(int x,int y,T z){
        D.add_edge(x,y,z);
    }
    void x_true_y_false_loss(int x,int y,T z){
        D.add_edge(y,x,z);
    }
    void x_true_y_true_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_false_loss(w,z);
        x_true_y_false_loss(w,x,inf);
        x_true_y_false_loss(w,y,inf);
    }
    void x_false_y_false_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_true_loss(w,z);
        x_false_y_true_loss(w,x,inf);
        x_false_y_true_loss(w,y,inf);
    }
    T build(){
        return D.max_flow(s,t)-sum;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<string> S(n);
    for (int i=0;i<n;++i) cin >> S[i];

    ProjectSelectionProblem<int> PSP(n*m);
    auto id=[&](int x,int y){return x*m+y;};
    int ans=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]!='#') continue;
            ++ans;
            for (int k=0;k<2;++k){
                int nx=i+dx[k],ny=j+dy[k];
                if (n<=nx||m<=ny) continue;
                if (S[nx][ny]!='#') continue;
                if (!k) PSP.x_true_y_true_profit(id(i,j),id(nx,ny),1);
                else PSP.x_false_y_false_profit(id(i,j),id(nx,ny),1);
            }
        }
    }

    cout << ans+PSP.build() << '\n';
}