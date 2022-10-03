#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<50;

int main(){
    
    int N;cin>>N;
    int sum=0;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    
    if(sum<=1){
        cout<<-1<<endl;
        return 0;
    }
    
    ll ans=INF;
    
    for(int k=2;k<=sum;k++){
        if(sum%k!=0) continue;
        
        ll cnt=0;
        
        vector<int> when;
        for(int i=0;i<N;i++){
            if(A[i]==1) when.push_back(i);
            
            if(when.size()==k){
                for(int a:when) cnt+=abs(a-when[k/2]);
                when.clear();
            }
        }
        
        ans=min(ans,cnt);
    }
    
    cout<<ans<<endl;
}