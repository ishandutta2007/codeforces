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
    
    int H,W;cin>>H>>W;
    vector<vector<int>> S(H,vector<int>(W));
    
    ll ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    
    for(int j=0;j<W;j++){
        
        vector<int> cnt(H);
        
        iota(all(cnt),H);
        
        for(int i=0;i<H;i++){
            if((S[i][j]-1)%W==j&&1<=S[i][j]&&S[i][j]<=H*W){
                int turn=i-(S[i][j]-1)/W;
                if(turn<0) turn+=H;
                
                cnt[turn]--;
            }
        }
        
        sort(all(cnt));
        
        ans+=cnt[0];
    }
    
    cout<<ans<<endl;
}