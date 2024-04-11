#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int when=0;when<T;when++){
        ll N,a,b;cin>>N>>a>>b;
        string S;cin>>S;
        
        ll ans=a*N+b*(N+1);
        int last=-1;
        
        for(int i=1;i<N;i++){
            if(S[i-1]=='0'&&S[i]=='0') continue;
            if(S[i-1]=='0'&&S[i]=='1'){
                if(last==-1) ans+=a+b;
                else ans+=min(2*a,b*(i-last-1))+b;
            }else if(S[i-1]=='1'&&S[i]=='0'){
                last=i;
                ans+=b;
            }else{
                ans+=b;
            }
            //cout<<i<<" "<<ans<<endl;
        }
        
        if(last!=-1) ans+=a;
        
        cout<<ans<<endl;
    }
}