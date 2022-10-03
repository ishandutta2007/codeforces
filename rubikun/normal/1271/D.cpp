#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<int> A(N),B(N),C(N),sum(N),last(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i]>>C[i];
        last[i]=i;
    }
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        last[b]=max(last[b],a);
    }
    
    priority_queue<int,vector<int>,greater<int>> PQ;
    sum[0]=K+B[0];
    
    for(int i=1;i<N;i++){
        sum[i]=sum[i-1]+B[i];
    }
    
    for(int i=0;i<N;i++){
        int can=INF;
        for(int j=i+1;j<N;j++){
            can=min(can,sum[j-1]-A[j]);
        }
        for(int j=0;j<N;j++){
            if(last[j]==i) PQ.push(C[j]);
        }
        
        if(i==N-1) can=sum[i];
        
        while(!PQ.empty()&&PQ.size()>can){
            PQ.pop();
        }
        
        if(can<0||K<A[0]){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    int ans=0;
    while(!PQ.empty()){
        ans+=PQ.top();
        PQ.pop();
    }
    cout<<ans<<endl;
}