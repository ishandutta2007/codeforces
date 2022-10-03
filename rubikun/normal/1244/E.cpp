#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003;
const ll INF=1LL<<35;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;ll K;cin>>N>>K;
    vector<ll> A(N),sum(N+1,0);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]+A[i-1];
    }
    
    ll ans=INF+5;
    
    for(ll i=0;i<N;i++){
        if(A[i]*i-sum[i]+(sum[N]-sum[i+1])-A[i]*(N-1-i)<=K){
            ans=0;
            continue;
        }
        ll left=0,right=INF;
        
        while(right-left>1){
            ll mid=(left+right)/2;
            int k=distance(A.begin(),upper_bound(all(A),A[i]+mid));
            if(A[i]*i-sum[i]+(sum[N]-sum[k])-(A[i]+mid)*(N-k)<=K) right=mid;
            else left=mid;
            //cout<<mid<<" "<<k<<endl;
        }
        
        ans=min(ans,right);
        
        //cout<<right<<endl;
    }
    
    if(ans==0){
        cout<<0<<endl;
        return 0;
    }
    
    for(ll i=0;i<N;i++){
        
        ll left=0,right=INF;
        
        while(right-left>1){
            ll mid=(left+right)/2;
            int k=distance(A.begin(),lower_bound(all(A),A[i]-mid));
            if((sum[N]-sum[i+1])-A[i]*(N-i-1)+(A[i]-mid)*k-sum[k]<=K) right=mid;
            else left=mid;
            //cout<<mid<<" "<<k<<endl;
        }
        
        ans=min(ans,right);
        
        //cout<<right<<endl;
    }
    
    
    cout<<ans<<endl;
}