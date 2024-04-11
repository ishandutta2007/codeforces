#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N+1);
    for(int i=0;i<N;i++) cin>>A[i+1];
    for(int i=1;i<=N;i++) A[i]^=A[i-1];
    
    map<int,int> MA0,MA1;
    for(int i=0;i<=N;i++){
        if(i%2==1) MA1[A[i]]++;
        else MA0[A[i]]++;
    }
    
    ll ans=0;
    
    for(int i=0;i<=N;i++){
        if(i%2==0){
            ans+=MA0[A[i]];
        }else{
            ans+=MA1[A[i]];
        }
        //cout<<ans<<endl;
    }
    
    cout<<(ans-(N+1))/2<<endl;
    
}