#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    while(N){
        ll C,sum;cin>>C>>sum;
        ll ans=0;
        ll right=sum%C,left=C-right;
        ans+=(sum/C)*(sum/C)*(left);
        ans+=(sum/C+1)*(sum/C+1)*right;
        cout<<ans<<"\n";
        
        N--;
    }
}