#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX],rG[MAX];
int dis[MAX],cnt[MAX];

void BFS(int t){
    dis[t]=0;
    cnt[t]=1;
    queue<int> Q;
    Q.push(t);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(dis[to]==INF){
                dis[to]=dis[u]+1;
                cnt[to]=cnt[u];
                
                Q.push(to);
            }else if(dis[to]==dis[u]+1){
                cnt[to]+=cnt[u];
                if(cnt[to]>=2) cnt[to]=2;
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[b].push_back(a);
        rG[a].push_back(b);
    }
    
    for(int i=0;i<N;i++) dis[i]=INF;
    
    int K;cin>>K;
    vector<int> A(K);
    
    for(int i=0;i<K;i++){
        cin>>A[i];
        A[i]--;
    }
    
    BFS(A[K-1]);
    
    int mini=0,maxi=0;
    
    for(int i=0;i<K-1;i++){
        
        int mi=INF;
        
        for(int to:rG[A[i]]){
            mi=min(mi,dis[to]);
        }
        
        int a=0;
        
        for(int to:rG[A[i]]){
            if(dis[to]==mi) a++;
        }
        
        if(dis[A[i+1]]!=mi){
            mini++;
            maxi++;
        }else if(a>=2) maxi++;
        
        //if(a>=2) maxi++;
    }
    
    cout<<mini<<" "<<maxi<<endl;
}