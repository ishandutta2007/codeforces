#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;N++;
    string S;cin>>S;
    S+='S';
    int cnt=0;
    for(int i=1;i<N;i++){
        if(S[i-1]=='G'&&S[i]=='S') cnt++;
    }
    if(cnt==0) cout<<0<<endl;
    else if(cnt==1){
        int ans=0;
        for(int i=0;i<N;i++){
            if(S[i]=='G') ans++;
        }
        cout<<ans<<endl;
    }else{
        vector<int> lcnt(N,0),rcnt(N,0);
        for(int i=1;i<N;i++){
            if(S[i-1]=='G') lcnt[i]=lcnt[i-1]+1;
            else lcnt[i]=0;
        }
        for(int i=N-2;i>=0;i--){
            if(S[i+1]=='G') rcnt[i]=rcnt[i+1]+1;
            else rcnt[i]=0;
        }
        
        int ans=0;
        for(int i=1;i<N-1;i++){
            if(S[i]=='S'&&cnt>2) ans=max(ans,lcnt[i]+rcnt[i]+1);
            if(S[i]=='S'&&cnt==2){
                if(S[i-1]=='G'&&S[i+1]=='G') ans=max(ans,lcnt[i]+rcnt[i]);
                else ans=max(ans,lcnt[i]+rcnt[i]+1);
            }
        }
        cout<<ans<<endl;
    }
}