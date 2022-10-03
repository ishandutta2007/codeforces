#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int H,W;cin>>H>>W;
    vector<vector<int>> S(H,vector<int>(W,-1));
    bool ok=true;
    for(int i=0;i<H;i++){
        int a;cin>>a;
        for(int j=0;j<a;j++){
            if(S[i][j]==0) ok=false;
            S[i][j]=1;
        }
        if(a!=W){
            if(S[i][a]==1) ok=false;
            S[i][a]=0;
        }
    }
    
    for(int j=0;j<W;j++){
        int a;cin>>a;
        for(int i=0;i<a;i++){
            if(S[i][j]==0) ok=false;
            S[i][j]=1;
        }
        if(a!=H){
            if(S[a][j]==1) ok=false;
            S[a][j]=0;
        }
    }
    
    if(!ok) cout<<0<<endl;
    else{
        ll ans=1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]==-1){
                    ans*=2;
                    ans%=mod;
                }
            }
        }
        cout<<ans<<endl;
    }
}