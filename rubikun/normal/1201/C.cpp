#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17;
const ll INF=1LL<<45;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;
    ll K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    sort(all(A));
    
    ll left=0,right=INF;
    
    while(right-left>1){
        ll mid=(left+right)/2;
        ll sum=0;
        
        for(int i=N/2;i<N;i++){
            sum+=max(0LL,mid-A[i]);
        }
        
        if(sum<=K) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}