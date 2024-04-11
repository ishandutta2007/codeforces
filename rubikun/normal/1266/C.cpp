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
    
    int R,C;cin>>R>>C;
    if(R==1&&C==1) cout<<0<<endl;
    else if(C!=1){
        vector<vector<ll>> ans(R,vector<ll>(C));
        
        for(int j=0;j<C;j++) ans[0][j]=R+1+j;
        
        for(int i=1;i<R;i++){
            for(int j=0;j<C;j++){
                ans[i][j]=ans[0][j]*(i+1);
            }
        }
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        for(int i=0;i<R;i++) cout<<i+2<<endl;
    }
}