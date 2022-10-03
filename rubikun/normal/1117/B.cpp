#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,M,K;cin>>N>>M>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    reverse(all(A));
    ll a=M/(K+1),b=M%(K+1);
    cout<<a*(A[0]*K+A[1])+b*A[0]<<endl;
}