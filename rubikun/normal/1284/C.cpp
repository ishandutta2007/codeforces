#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
ll mo;
ll bik[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N>>mo;
    bik[0]=1;
    bik[1]=1;
    for(ll i=2;i<MAX;i++){
        bik[i]=bik[i-1]*i%mo;
    }
    
    ll sum=0;
    
    for(ll i=1;i<=N;i++){
        sum+=bik[i]*bik[N-i]%mo*(N-i+1)%mo*(N-i+1)%mo;
        sum%=mo;
    }
    
    cout<<sum<<endl;
}