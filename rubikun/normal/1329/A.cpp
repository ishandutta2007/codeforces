#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<ll> A(M),ans(M),S(M+1);
    for(int i=0;i<M;i++) cin>>A[i];
    
    bool ok=true;
    ll sum=0;
    for(int i=0;i<M;i++){
        sum+=A[i];
        if(i+A[i]>N) ok=false;
        S[i+1]=S[i]+A[i];
    }
    
    if(sum<N) ok=false;
    
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    
    ans[0]=1;
    ll now=A[0];
    
    for(int i=1;i<M;i++){
        ll to=now+S[M]-S[i];
        if(to==N){
            ans[i]=now+1;
            now+=A[i];
        }else{
            ll diff=A[i-1]-1;
            now-=min(diff,to-N);
            ans[i]=now+1;
            now+=A[i];
        }
    }
    
    for(int i=0;i<M;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}