#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N+1);
    int where=-1;
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        if(A[i+1]==-1) where=i+1;
    }
    
    for(int i=0;i<=where;i++){
        A[i]=0;
    }
    
    int can=N,now=N;
    ll ans=0;
    
    priority_queue<ll,vector<ll>,greater<ll>> PQ;
    
    while(now>0){
        while(now>=can){
            PQ.push(A[now]);
            now--;
        }
        ans+=PQ.top();
        PQ.pop();
        can/=2;
    }
    
    cout<<ans<<endl;
    
}