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
    
    int T;cin>>T;
    while(T--){
        ll A,B;cin>>A>>B;
        A=abs(A-B);
        
        if(A==0){
            cout<<0<<endl;
            continue;
        }
        
        for(ll i=1;;i++){
            ll maxi=i*(i+1)/2;
            if(maxi>=A){
                if(maxi%2==A%2){
                    cout<<i<<endl;
                    break;
                }else{
                    if((i+1)%2==0) cout<<i+2<<endl;
                    else cout<<i+1<<endl;
                    
                    break;
                }
            }
        }
    }
}