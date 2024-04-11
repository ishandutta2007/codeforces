#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N+1),sum(N+1),cnt1(N+1),cnt2(N+1);
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        if(A[i+1]>0) A[i+1]=0;
        else A[i+1]=1;
        sum[i+1]=sum[i]+A[i+1];
    }
    
    for(int i=1;i<N+1;i++){
        cnt1[i]=cnt1[i-1];
        cnt2[i]=cnt2[i-1];
        if(sum[i]%2==0){
            cnt1[i]++;
        }else cnt2[i]++;
    }
    
    ll ans=0;
    
    for(int i=1;i<=N;i++){
        if(A[i]==1){
            if(sum[i]%2==0){
                ans+=cnt1[N]-cnt1[i-1];
            }else{
                ans+=cnt2[N]-cnt2[i-1];
            }
        }else{
            if(sum[i]%2==1){
                ans+=cnt1[N]-cnt1[i-1];
            }else{
                ans+=cnt2[N]-cnt2[i-1];
            }
        }
        //cout<<ans<<endl;
    }
    
    cout<<ans<<" "<<ll(N+1)*ll(N)/2-ans<<endl;
    
}