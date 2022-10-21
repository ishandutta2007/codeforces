#include <bits/stdc++.h>
using namespace std;

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

void CFR668_E(){
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
                int nx=i+(k^1),ny=j+k;
                if (n<=nx||m<=ny) continue;
                if (S[nx][ny]!='#') continue;
                if (!k) PSP.x_true_y_true_profit(id(i,j),id(nx,ny),1);
                else PSP.x_false_y_false_profit(id(i,j),id(nx,ny),1);
            }
        }
    }

    cout << ans+PSP.build() << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    CFR668_E();
}