#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX];
int siz[MAX],dis[MAX];

void DFS(int u,int p){
    siz[u]=1;
    for(int to:G[u]){
        if(to==p) continue;
        dis[to]=dis[u]+1;
        DFS(to,u);
        siz[u]+=siz[to];
    }
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    DFS(0,-1);
    
    vector<ll> ans(N);
    for(int i=0;i<N;i++){
        ans[i]=dis[i]-(siz[i]-1);
    }
    sort(all(ans));
    reverse(all(ans));
    
    ll sum=0;
    
    for(int i=0;i<K;i++) sum+=ans[i];
    
    cout<<sum<<endl;
}