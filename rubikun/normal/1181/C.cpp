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
    
    ll ans=0;
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++){
        cin>>S[i];
    }
    vector<vector<int>> can(H,vector<int>(W));
    
    for(int j=0;j<W;j++){
        can[H-1][j]=H-1;
        for(int i=H-2;i>=0;i--){
            if(S[i][j]==S[i+1][j]) can[i][j]=can[i+1][j];
            else can[i][j]=i;
        }
    }
    
    for(int k=1;k*3<=H;k++){
        for(int i=0;i+k*3<=H;i++){
            int nowj=0,cnt=0;
            
            while(nowj<W){
                if(can[i][nowj]==i+k-1&&can[i+k][nowj]==i+2*k-1&&can[i+k*2][nowj]>=i+3*k-1){
                    if(cnt==0){
                        cnt++;
                    }else{
                        if(S[i][nowj-1]==S[i][nowj]&&S[i+k][nowj-1]==S[i+k][nowj]&&S[i+k*2][nowj-1]==S[i+k*2][nowj]) cnt++;
                        else{
                            ans+=cnt*(cnt+1)/2;
                            cnt=1;
                        }
                    }
                }else{
                    if(cnt){
                        ans+=cnt*(cnt+1)/2;
                        cnt=0;
                    }
                }
                
                nowj++;
            }
            
            ans+=cnt*(cnt+1)/2;
        }
    }
    
    cout<<ans<<endl;
}