#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=105,INF=1<<30;

//Union Find


struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

vector<int> G[MAX];

void make_all_Prufer(vector<vector<int>> &S,vector<int> &now,int N){
    if(si(now)==N-2){
        S.push_back(now);
        return;
    }
    for(int i=0;i<N;i++){
        now.push_back(i);
        make_all_Prufer(S,now,N);
        now.pop_back();
    }
}

vector<vector<pair<int,int>>> make_all_tree(int N){
    vector<vector<pair<int,int>>> res;
    vector<vector<int>> pru;
    vector<int> mu;
    make_all_Prufer(pru,mu,N);
    
    for(auto A:pru){
        res.push_back({});
        vector<int> deg(N,1);
        for(int i=0;i<si(A);i++){
            deg[A[i]]++;
        }
        for(int i=0;i<si(A);i++){
            for(int j=0;j<N;j++){
                if(deg[j]==1){
                    res.back().push_back(mp(A[i],j));
                    deg[A[i]]--;
                    deg[j]--;
                    break;
                }
            }
        }
        int u=-1,v=-1;
        for(int i=0;i<N;i++){
            if(deg[i]==1){
                if(u==-1) u=i;
                else v=i;
            }
        }
        res.back().push_back(mp(u,v));
    }
    return res;
    
    // N 0-indexed
}

vector<int> GG[MAX];

vector<vector<vector<int>>> makeinput(vector<pair<int,int>> E){
    int N=si(E)+1;
    for(int i=0;i<N;i++) GG[i].clear();
    for(auto e:E){
        //uf.unite(e.fi,e.se);
        GG[e.fi].push_back(e.se);
        GG[e.se].push_back(e.fi);
    }
    
    vector<vector<vector<int>>> res(N,vector<vector<int>>(N,vector<int>(N)));
    
    for(int k=0;k<N;k++){
        vector<int> dis(N,INF);
        dis[k]=0;
        queue<int> Q;Q.push(k);
        
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int to:GG[u]){
                if(chmin(dis[to],dis[u]+1)) Q.push(to);
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) continue;
                bool a=(dis[i]==dis[j]);
                res[i][j][k]=a;
            }
        }
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N;cin>>N;
        vector<vector<vector<int>>> f(N,vector<vector<int>>(N,vector<int>(N)));
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                string S;cin>>S;
                for(int k=0;k<N;k++){
                    f[i][j][k]=f[j][i][k]=(int)(S[k]-'0');
                }
            }
        }
        
        set<pair<int,int>> ans;
        
        for(int t=1;t<N;t++){
            set<pair<int,int>> unseen,seen;
            unseen.insert(mp(0,t));
            while(1){
                if(si(seen)+si(unseen)>N-1) break;
                if(si(unseen)==0) break;
                auto [a,b]=*unseen.begin();
                unseen.erase(mp(a,b));
                seen.insert(mp(a,b));
                for(int q=0;q<2;q++){
                    for(int k=0;k<N;k++){
                        if(k==a) continue;
                        if(k==b) continue;
                        if(f[a][k][b]){
                            if(!seen.count(mp(min(b,k),max(b,k)))&&!unseen.count(mp(min(b,k),max(b,k)))){
                                unseen.insert(mp(min(b,k),max(b,k)));
                            }
                        }
                    }
                    swap(a,b);
                }
            }
            if(si(seen)!=N-1) continue;
            
            for(int i=0;i<N;i++) G[i].clear();
            
            UF uf;uf.init(N);
            for(auto e:seen){
                uf.unite(e.fi,e.se);
                G[e.fi].push_back(e.se);
                G[e.se].push_back(e.fi);
            }
            
            bool ok=true;
            for(int k=0;k<N;k++){
                vector<int> dis(N,INF);
                dis[k]=0;
                queue<int> Q;Q.push(k);
                
                while(!Q.empty()){
                    int u=Q.front();Q.pop();
                    for(int to:G[u]){
                        if(chmin(dis[to],dis[u]+1)) Q.push(to);
                    }
                }
                
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        if(i==j) continue;
                        bool a=(dis[i]==dis[j]);
                        bool b=f[i][j][k];
                        ok&=(a==b);
                    }
                }
            }
            ok&=(uf.size[uf.root(0)]==N);
            
            if(ok){
                ans=seen;
            }
        }
        
        if(si(ans)==0){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
            for(auto e:ans) cout<<e.fi+1<<" "<<e.se+1<<"\n";
        }
    }
}