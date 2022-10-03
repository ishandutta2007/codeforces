#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++){
            cin>>S[i];
        }
        set<int> SE;
        int mini=INF;
        for(int i=0;i<H;i++){
            int cnt=0;
            for(int j=0;j<W;j++){
                if(S[i][j]=='.') cnt++;
            }
            mini=min(mini,cnt);
        }
        
        for(int i=0;i<H;i++){
            int cnt=0;
            for(int j=0;j<W;j++){
                if(S[i][j]=='.') cnt++;
            }
            if(cnt==mini){
                for(int j=0;j<W;j++){
                    if(S[i][j]=='.') SE.insert(j);
                }
            }
        }
        
        int mini2=INF;
        for(int j=0;j<W;j++){
            int cnt=0;
            for(int i=0;i<H;i++){
                if(S[i][j]=='.') cnt++;
            }
            mini2=min(mini2,cnt);
        }
        bool ok=false;
        
        for(int j=0;j<W;j++){
            int cnt=0;
            for(int i=0;i<H;i++){
                if(S[i][j]=='.') cnt++;
            }
            if(cnt==mini2){
                for(int i=0;i<H;i++){
                    if(S[i][j]=='.'){
                        auto it=SE.find(j);
                        if(it!=SE.end()) ok=true;
                    }
                }
            }
        }
        if(ok) cout<<mini+mini2-1<<endl;
        else cout<<mini+mini2<<endl;
    }
}