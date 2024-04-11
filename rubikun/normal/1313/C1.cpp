#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),ans(N);
    ll maxi=0;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        vector<ll> B(N);
        ll mae=A[i];
        B[i]=mae;
        for(int j=i-1;j>=0;j--){
            B[j]=min(mae,A[j]);
            mae=B[j];
        }
        mae=A[i];
        for(int j=i+1;j<N;j++){
            B[j]=min(mae,A[j]);
            mae=B[j];
        }
        
        ll sum=0;
        for(int j=0;j<N;j++) sum+=B[j];
        
        if(sum>maxi){
            maxi=sum;
            ans=B;
        }
        
    }
    
    for(ll a:ans) cout<<a<<" ";
    cout<<endl;
}