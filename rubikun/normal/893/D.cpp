#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;

int main(){
    
    int N;
    ll D;cin>>N>>D;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    int cnt=0;
    ll now=0,maxi=0;
    int i=0;
    bool ok=true;
    
    while(1){
        while(i<N&&A[i]!=0){
            now+=A[i];
            maxi=max(maxi,now);
            i++;
        }
        if(maxi>D) ok=false;
        if(i<N&&now<0&&A[i]==0){
            if(cnt&&D-maxi>=-now){
                maxi+=-now;
                now=0;
            }else{
                cnt++;
                now=0;
                maxi=0;
            }
        }
        
        if(i>=N-1) break;
        
        i++;
    }
    
    if(ok) cout<<cnt<<endl;
    else cout<<-1<<endl;
    
    
}