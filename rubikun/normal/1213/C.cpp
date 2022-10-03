#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        ll N,M;cin>>N>>M;
        ll ans=0;
        if(M%10==0) ans=0;
        else if(M%10==1||M%10==3||M%10==7||M%10==9){
            ans+=N/(M*10)*45;
            N-=N/(M*10)*(M*10);
            int cnt=1;
            while(N>=M){
                N-=M;
                ans+=(M%10*cnt)%10;
                cnt++;
            }
        }else if(M%10==2||M%10==4||M%10==6||M%10==8){
            ans+=N/(M*10)*40;
            N-=N/(M*10)*(M*10);
            int cnt=1;
            while(N>=M){
                N-=M;
                ans+=(M%10*cnt)%10;
                cnt++;
            }
        }else{
            ans+=N/(M*10)*25;
            N-=N/(M*10)*(M*10);
            int cnt=1;
            while(N>=M){
                N-=M;
                ans+=(M%10*cnt)%10;
                cnt++;
            }
        }
        cout<<ans<<endl;
    }
}