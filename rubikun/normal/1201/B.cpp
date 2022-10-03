#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    
    sort(all(A));
    
    if(sum%2==1||A[N-1]*2>sum) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}