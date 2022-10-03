#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

ll f(ll a,ll m){
    if(a==1) return 2%m;
    
    if(a%2){
        for(int i=35;i>=0;i--){
            if(a&(1LL<<i)){
                return (f(a-1,m)+f((1LL<<i)-1,m))%m;
            }
        }
    }
    
    for(int i=35;i>=0;i--){
        if(a&(1LL<<i)){
            if(a==(1LL<<i)) return f(a/2,m)*(a/2+1)%m;
            
            return f(1LL<<i,m)*((a-(1LL<<i))/2+1)%m;
        }
    }
    
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll d,m;cin>>d>>m;
        cout<<(m+f(d,m)-1)%m<<"\n";
    }
}