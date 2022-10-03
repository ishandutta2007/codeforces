#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=7005,INF=1<<30;
vector<int> G[MAX],used(MAX);

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    used[u]=1;
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i];
            if(used[b]) continue;
            used[b]=1;
            Q.push(b);
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N),B(N),can(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(A[i]-A[j]==(A[i]^A[j])) G[i].push_back(j);
            if(A[i]==A[j]) can[i]=1;
        }
    }
    
    for(int i=0;i<N;i++){
        if(can[i]&&!used[i]) BFS(i);
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        if(used[i]) ans+=B[i];
    }
    
    cout<<ans<<endl;
}