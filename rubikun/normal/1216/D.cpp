#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    
    ll a=A[N-1]-A[0];
    
    for(int i=1;i<N-1;i++){
        a=gcd(a,A[N-1]-A[i]);
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=(A[N-1]-A[i])/a;
    }
    
    cout<<ans<<" "<<a<<endl;
}