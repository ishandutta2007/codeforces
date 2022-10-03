#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
   
    int N,M;cin>>N>>M;
    vector<ll> A(M),B(N+1,0),imos(N+1,0);
    ll sum=0;
    for(int i=0;i<M;i++){
        cin>>A[i];
        if(i){
            sum+=abs(A[i]-A[i-1]);
            ll a=min(A[i-1],A[i]),b=max(A[i-1],A[i]);
            if(b-a>=1){
                imos[a+1]--;
                imos[b]++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        imos[i]+=imos[i-1];
    }
    
    for(int i=1;i<=N;i++){
        B[i]+=sum+imos[i];
    }
    
    for(int i=0;i<M;i++){
        
        if(i==0){
            if(A[i]<A[i+1]){
                B[A[i]]+=A[i]-1;
            }else if(A[i]>A[i+1]){
                B[A[i]]+=2*A[i+1]-A[i];
            }
        }else if(i==M-1){
            if(A[i-1]<A[i]){
                B[A[i]]+=2*A[i-1]-A[i];
            }else if(A[i-1]>A[i]){
                B[A[i]]+=A[i]-1;
            }
        }else{
            if(A[i]<A[i+1]){
                B[A[i]]+=A[i]-1;
            }else if(A[i]>A[i+1]){
                B[A[i]]+=2*A[i+1]-A[i];
            }
            
            if(A[i-1]<A[i]){
                B[A[i]]+=2*A[i-1]-A[i];
            }else if(A[i-1]>A[i]){
                B[A[i]]+=A[i]-1;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    
}