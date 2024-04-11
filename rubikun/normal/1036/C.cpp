#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=(((1<<30)-1)<<1)+1;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        ll a,b;cin>>a>>b;
        a--;
        string L=to_string(a),R=to_string(b);
        string zero="0000000000000000000";
        L=zero.substr(0,19-L.size())+L;
        R=zero.substr(0,19-R.size())+R;
        ll dp[20][5][2];
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0][0]=1;
        
        for(int i=0;i<19;i++){
            for(int j=0;j<=3;j++){
                if(L[i]=='0'){
                    dp[i+1][j][0]+=dp[i][j][0];
                }else{
                    dp[i+1][j][1]+=dp[i][j][0];
                    dp[i+1][j+1][1]+=dp[i][j][0]*(L[i]-'1');
                    dp[i+1][j+1][0]+=dp[i][j][0];
                }
                
                dp[i+1][j][1]+=dp[i][j][1];
                dp[i+1][j+1][1]+=dp[i][j][1]*9;
            }
        }
        
        ll l=0,r=0;
        for(int j=0;j<=3;j++){
            l+=dp[19][j][0]+dp[19][j][1];
        }
        
        memset(dp,0,sizeof(dp));
        
        dp[0][0][0]=1;
        
        for(int i=0;i<19;i++){
            for(int j=0;j<=3;j++){
                if(R[i]=='0'){
                    dp[i+1][j][0]+=dp[i][j][0];
                }else{
                    dp[i+1][j][1]+=dp[i][j][0];
                    dp[i+1][j+1][1]+=dp[i][j][0]*(R[i]-'1');
                    dp[i+1][j+1][0]+=dp[i][j][0];
                }
                
                dp[i+1][j][1]+=dp[i][j][1];
                dp[i+1][j+1][1]+=dp[i][j][1]*9;
            }
        }
        
        for(int j=0;j<=3;j++){
            r+=dp[19][j][0]+dp[19][j][1];
        }
        
        cout<<r-l<<endl;
        
        Q--;
    }
}