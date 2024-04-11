#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=500003,INF=1<<30;
vector<pair<int,ll>> G[MAX];

pair<ll,ll> DFS(int u,int p,int limit){
    vector<ll> diff;
    ll sum=0;
    
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i].first;ll b=G[u][i].second;
        if(a==p) continue;
        
        pair<ll,ll> p=DFS(a,u,limit);
        
        sum+=p.first;
        diff.push_back(b+p.second-p.first);
    }
    
    sort(diff.rbegin(),diff.rend());
    
    ll ans1=sum,ans2=sum;
    for(int i=0;i<min(limit-1,int(diff.size()));i++) ans2+=max(0LL,diff[i]);
    for(int i=0;i<min(limit,int(diff.size()));i++) ans1+=max(0LL,diff[i]);
    
    return make_pair(ans1,ans2);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        
        int N,K;//cin>>N>>K;
        scanf("%d%d",&N,&K);
        
        for(int i=0;i<=N;i++){
            G[i].clear();
        }
        
        for(int i=0;i<N-1;i++){
            int a,b;ll c;//cin>>a>>b>>c;
            scanf("%d%d%lld",&a,&b,&c);
            a--;b--;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        
        pair<ll,ll> ans=DFS(0,-1,K);
        
        printf("%lld\n",ans.first);
        
        Q--;
        
    }
}