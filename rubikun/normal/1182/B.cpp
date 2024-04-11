#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> dh={0,1,0,-1},dw={1,0,-1,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    
    bool ok=false;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='*'){
                bool check=true;
                for(int k=0;k<4;k++){
                    int toh=i+dh[k],tow=j+dw[k];
                    if(toh<0||toh>=H||tow<0||tow>=W){
                        check=false;
                        continue;
                    }
                    if(S[toh][tow]=='.') check=false;
                }
                if(check){
                    ok=true;
                    S[i][j]='.';
                    
                    for(int k=0;k<4;k++){
                        int h=i+dh[k],w=j+dw[k];
                        while(h>=0&&h<H&&w>=0&&w<W&&S[h][w]=='*'){
                            S[h][w]='.';
                            h+=dh[k];
                            w+=dw[k];
                        }
                    }
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='*') ok=false;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}