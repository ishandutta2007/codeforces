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
    
    int Q;cin>>Q;
    while(Q--){
        int x;cin>>x;
        string S;cin>>S;
        ll over=0;
        int now=1;
        while(now<=x){
            ll cnt=S[now-1]-'0';
            ll rem=S.size()-now;
            if(S.size()<x&&over==0){
                string T;
                if(cnt!=1) T=S.substr(now,rem);
                for(int i=1;i<cnt;i++){
                    if(S.size()>=x){
                        over+=rem;
                    }else{
                        S+=T;
                    }
                }
                if(S.size()>=x){
                    over+=S.size()-x;
                    S=S.substr(0,x);
                }
            }else over+=(cnt-1)*(rem+over);
            
            over%=mod;
            now++;
            
            //cout<<S.size()<<endl;
        }
        
        cout<<(S.size()+over)%mod<<endl;
    }
}