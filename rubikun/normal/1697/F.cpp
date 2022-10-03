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
const int mod=998244353,MAX=500005,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

int get_id(int i,bool f){
    return 2*i+f;
}

void add_edge(int from,int to){
    //cout<<from<<" "<<to<<endl;
    G[from].push_back(to);
    rG[to].push_back(from);
}

void either(int i,bool f,int j,bool g){
    add_edge(get_id(i,!f),get_id(j,g));
    add_edge(get_id(j,!g),get_id(i,f));
    //add_edge(2*i+(!f),2*j+g);
    //add_edge(2*j+(!g),2*i+f);
}

void imply(int i,bool f,int j,bool g){
    either(i,!f,j,g);
}
//ifjg

void must(int i,bool f){
    either(i,f,i,f);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

void init(int sz){
    V=sz;
    for(int i=0;i<V;i++){
        cmp[i]=0;
        G[i].clear();
        rG[i].clear();
        used[i]=false;
    }
    vs.clear();
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M,K;cin>>N>>M>>K;
        init(N*(K+1)*2);
        
        auto f=[&](int i,int x){
            return i*(K+1)+x-1;
        };
        //ix
        
        for(int i=0;i<N;i++){
            for(int j=1;j<=K+1;j++){
                if(j<=K){
                    imply(f(i,j+1),1,f(i,j),1);
                }
                
                if(i<N-1){
                    imply(f(i,j),1,f(i+1,j),1);
                    //add_edge(f(i,j,1),f(i+1,j,1));
                    //add_edge(f(i+1,j-1,0),f(i,j-1,0));
                }
            }
            must(f(i,1),1);
            must(f(i,K+1),0);
        }
        
        for(int i=0;i<M;i++){
            int t;cin>>t;
            if(t==1){
                int a,b;cin>>a>>b;a--;
                either(f(a,b),0,f(a,b+1),1);
                //add_edge(f(a,b,1),f(a,b+1,1));
                //add_edge(f(a,b,0),f(a,b-1,0));
            }
            if(t==2){
                int a,b,c;cin>>a>>b>>c;a--;b--;
                for(int j=1;j<=K;j++){
                    if(j>=c){
                        must(f(a,j),0);
                        must(f(b,j),0);
                        //either(f(a,j),1,f(b,1),0);
                        //either(f(b,j),1,f(a,1),0);
                        //add_edge(f(a,j,1),f(a,j-1,0));
                        //add_edge(f(b,j,1),f(b,j-1,0));
                    }else if(j+K>c){
                        imply(f(a,j),1,f(b,c+1-j),0);
                        imply(f(b,j),1,f(a,c+1-j),0);
                        //add_edge(f(a,j,1),f(b,c-j,0));
                        //add_edge(f(b,j,1),f(a,c-j,0));
                    }
                }
            }
            if(t==3){
                int a,b,c;cin>>a>>b>>c;a--;b--;
                for(int j=2;j<=K+1;j++){
                    if(j-1+K<c){
                        must(f(a,j),1);
                        must(f(b,j),1);
                        //add_edge(f(a,j,0),f(a,j+1,1));
                        //add_edge(f(b,j,0),f(b,j+1,1));
                    }else if(j-1+1<c){
                        imply(f(a,j),0,f(b,c-(j-1)),1);
                        imply(f(b,j),0,f(a,c-(j-1)),1);
                        //add_edge(f(a,j,0),f(b,c-j,1));
                        //add_edge(f(b,j,0),f(a,c-j,1));
                    }
                }
            }
        }
        
        scc();
        
        vector<int> ans(N,-1);
        
        bool ok=true;
        
        for(int i=0;i<N;i++){
            for(int j=1;j<=K+1;j++){
                if(cmp[get_id(f(i,j),1)]==cmp[get_id(f(i,j),0)]){
                    //cout<<i<<" "<<j<<endl;
                    ok=false;
                    break;
                }
                if(cmp[get_id(f(i,j),1)]>cmp[get_id(f(i,j),0)]){
                    ans[i]=j;
                    //break;
                }
            }
            if(ans[i]==-1){
                ok=false;
                break;
            }
        }
        
        if(ok){
            for(int a:ans) cout<<a<<" ";
            cout<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}