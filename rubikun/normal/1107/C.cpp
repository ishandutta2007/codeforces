#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    string S;cin>>S;
    S+=')';
    int i=0;
    ll ans=0;
    while(i<N){
        priority_queue<ll> PQ;
        while(1){
            PQ.push(A[i]);
            if(S[i]!=S[i+1]) break;
            i++;
        }
        for(int k=0;k<K;k++){
            ans+=PQ.top();
            PQ.pop();
            if(PQ.empty()) break;
        }
        i++;
    }
    cout<<ans<<endl;
}