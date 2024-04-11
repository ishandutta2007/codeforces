#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=(((1<<30)-1)<<1)+1;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N;
    vector<ll> A(N+1);
    for(int i=0;i<N;i++) cin>>A[i+1];
    cin>>M;
    vector<ll> B(M);
    for(int i=0;i<M;i++) cin>>B[i];
    
    for(int i=1;i<N+1;i++) A[i]+=A[i-1];
    
    int cnt=0;
    
    ll bsum=0;
    for(int j=0;j<M;j++){
        bsum+=B[j];
        if(binary_search(all(A),bsum)) cnt++;
    }
    
    if(bsum!=A[N]) cout<<-1<<endl;
    else cout<<cnt<<endl;
}