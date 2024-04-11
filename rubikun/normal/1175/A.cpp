#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1000001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        ll a,b;cin>>a>>b;
        ll ans=0;
        while(a){
            if(a%b!=0){
                ans+=a%b;
                a-=a%b;
            }
            while(a&&a%b==0){
                a/=b;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}