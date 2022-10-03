#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=700005,INF=1<<20;

int par[MAX],cost[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    
    for(int i=0;i<(n-2)/2;i++){
        cost[i]=0;
        cost[(n-2)/2+i]=1;
    }
    cost[n-1]=INF;
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        cost[root(a)]+=cost[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<vector<int>> T(N,vector<int>(2,-1));
    
    string S;cin>>S;
    
    for(int i=0;i<K;i++){
        int a;cin>>a;
        while(a--){
            int b;cin>>b;
            b--;
            
            if(T[b][0]==-1) T[b][0]=i;
            else T[b][1]=i;
        }
    }
    
    init(2*K+2);
    
    ll sum=0;
    
    for(int i=0;i<N;i++){
        int u,v;
        if(S[i]=='1'){
            if(T[i][0]!=-1){
                if(T[i][1]==-1){
                    u=T[i][0];
                    v=-1;
                    
                    if(!check(u,2*K)){
                        sum+=max(cost[root(u)],cost[root(u+K)]);
                        sum+=max(cost[root(2*K)],cost[root(2*K+1)]);
                        
                        unite(u,2*K);
                        unite(u+K,2*K+1);
                        
                        sum-=max(cost[root(u)],cost[root(u+K)]);
                    }
                }else{
                    u=T[i][0];
                    v=T[i][1];
                    
                    if(!check(u,v)){
                        sum+=max(cost[root(u)],cost[root(u+K)]);
                        sum+=max(cost[root(v)],cost[root(v+K)]);
                        
                        unite(u,v);
                        unite(u+K,v+K);
                        
                        sum-=max(cost[root(u)],cost[root(u+K)]);
                    }
                }
            }
        }else{
            if(T[i][0]!=-1){
                if(T[i][1]==-1){
                    u=T[i][0];
                    v=-1;
                    
                    if(!check(u,2*K+1)){
                        sum+=max(cost[root(u)],cost[root(u+K)]);
                        sum+=max(cost[root(2*K+1)],cost[root(2*K)]);
                        
                        unite(u,2*K+1);
                        unite(u+K,2*K);
                        
                        sum-=max(cost[root(u)],cost[root(u+K)]);
                    }
                }else{
                    u=T[i][0];
                    v=T[i][1];
                    
                    if(!check(u,v+K)){
                        sum+=max(cost[root(u)],cost[root(u+K)]);
                        sum+=max(cost[root(v+K)],cost[root(v)]);
                        
                        unite(u,v+K);
                        unite(u+K,v);
                        
                        sum-=max(cost[root(u)],cost[root(u+K)]);
                    }
                }
            }
        }
        
        cout<<sum<<endl;
    }
}