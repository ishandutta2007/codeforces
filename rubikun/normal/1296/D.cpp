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
    
    int N;
    ll A,B,K;cin>>N>>A>>B>>K;
    vector<ll> need(N);
    for(int i=0;i<N;i++){
        ll h;cin>>h;
        h%=(A+B);
        if(h==0) h+=A+B;
        
        need[i]=(h+A-1)/A-1;
    }
    sort(all(need));
    
    ll sum=0,ans=N;
    for(int i=0;i<N;i++){
        if(sum+need[i]<=K){
            sum+=need[i];
        }else{
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}