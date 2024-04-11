#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        int N,X;cin>>N>>X;
        string S;cin>>S;
        vector<int> cnt(N+1);
        for(int i=0;i<N;i++){
            if(S[i]=='0') cnt[i+1]=cnt[i]+1;
            else cnt[i+1]=cnt[i]-1;
        }
        
        if(cnt[N]==0){
            bool ok=false;
            
            for(int i=0;i<N;i++) if(cnt[i+1]==X) ok=true;
            
            if(ok) cout<<-1<<endl;
            else if(X==0) cout<<1<<endl;
            else cout<<0<<endl;
        }else if(cnt[N]>0){
            int ans=0;
            
            for(int i=1;i<=N;i++){
                if(cnt[i]<=X&&(X-cnt[i])%cnt[N]==0) ans++;
            }
            
            if(X==0) ans++;
            
            cout<<ans<<endl;
        }else{
            int ans=0;
            
            for(int i=1;i<=N;i++){
                if(cnt[i]>=X&&(cnt[i]-X)%abs(cnt[N])==0) ans++;
            }
            
            if(X==0) ans++;
            
            cout<<ans<<endl;
        }
    }
}