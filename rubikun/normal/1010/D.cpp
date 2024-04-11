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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

int dp[MAX][2];
int type[MAX],def[MAX];
vector<int> G[MAX];

void make(int u){
    if(type[u]<=1) def[u]=type[u];
    else{
        for(int to:G[u]){
            make(to);
        }
        if(type[u]==2) def[u]=def[G[u][0]]&def[G[u][1]];
        if(type[u]==3) def[u]=def[G[u][0]]|def[G[u][1]];
        if(type[u]==4) def[u]=def[G[u][0]]^def[G[u][1]];
        if(type[u]==5) def[u]=!def[G[u][0]];
    }
}

void DFS(int u,int p){
    if(type[u]<=1) return;
    
    for(int i=0;i<si(G[u]);i++){
        int to=G[u][i];
        
        if(type[u]==5){
            dp[to][0]=dp[u][1];
            dp[to][1]=dp[u][0];
        }
        else{
            int ne=G[u][i^1];
            
            if(type[u]==2){
                if(def[ne]){
                    dp[to][0]=dp[u][0];
                    dp[to][1]=dp[u][1];
                }else{
                    dp[to][0]=dp[u][0];
                    dp[to][1]=dp[u][0];
                }
            }
            if(type[u]==3){
                if(def[ne]){
                    dp[to][0]=dp[u][1];
                    dp[to][1]=dp[u][1];
                }else{
                    dp[to][0]=dp[u][0];
                    dp[to][1]=dp[u][1];
                }
            }
            if(type[u]==4){
                if(def[ne]){
                    dp[to][0]=dp[u][1];
                    dp[to][1]=dp[u][0];
                }else{
                    dp[to][0]=dp[u][0];
                    dp[to][1]=dp[u][1];
                }
            }
        }
        
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> leaf;
    for(int i=0;i<N;i++){
        string S;cin>>S;
        if(S=="IN"){
            leaf.push_back(i);
            cin>>type[i];
        }else{
            if(S=="AND") type[i]=2;
            if(S=="OR") type[i]=3;
            if(S=="XOR") type[i]=4;
            if(S=="NOT") type[i]=5;
            int a;cin>>a;a--;
            G[i].push_back(a);
            
            if(S!="NOT"){
                cin>>a;a--;
                G[i].push_back(a);
            }
        }
    }
    
    make(0);
    
    dp[0][0]=0;
    dp[0][1]=1;
    
    DFS(0,-1);
    
    for(int a:leaf){
        cout<<dp[a][!type[a]];
    }
    cout<<endl;
}