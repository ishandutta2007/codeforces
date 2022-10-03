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
const int mod=1000000007,MAX=200005,INF=1<<30;
ll sum=0;
vector<int> ans;
ll A[MAX];
vector<int> G[MAX],G2[MAX],rG2[MAX];
ll dp[MAX];

bool start[MAX];

void DFS(int u){
    dp[u]+=A[u];
    
    for(int to:G[u]){
        DFS(to);
        
        if(dp[to]>0){
            G2[u].push_back(to);
            rG2[to].push_back(u);
            start[u]=1;
            dp[u]+=dp[to];
        }
    }
    
    sum+=dp[u];
}

bool used[MAX];

void DFS2(int u,int r){
    if(!used[u]&&u!=r){
        ans.push_back(u);
        used[u]=1;
    }
    for(int to:G2[u]) DFS2(to,r);
}

void DFS3(int u){
    if(!used[u]) ans.push_back(u);
    used[u]=1;
    for(int to:G[u]) DFS3(to);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    vector<int> root;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(a==-1) root.push_back(i);
        else{
            a--;
            G[a].push_back(i);
        }
    }
    
    for(int a:root){
        DFS(a);
    }
    
    cout<<sum<<endl;
    
    for(int i=0;i<N;i++){
        if(si(rG2[i])==0&&start[i]){
            DFS2(i,i);
        }
    }
    
    reverse(all(ans));
    
    for(int a:root){
        DFS3(a);
    }
    
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}