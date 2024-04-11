#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        
        if(W<=3){
            for(int i=0;i<H;i++){
                S[i][0]='X';
                for(int j=1;j<W;j++){
                    if(S[i][j]=='X'){
                        for(int k=j;k>=1;k--) S[i][k]='X';
                    }
                }
            }
            
            for(int i=0;i<H;i++) cout<<S[i]<<"\n";
            continue;
        }
        
        for(int j=0;j<W;j+=3){
            int aru=-1;
            for(int i=0;i<H;i++){
                S[i][j]='X';
                for(int k=j+1;k<min(W,j+3);k++) if(S[i][k]=='X') aru=i;
            }
            if(aru==-1) for(int k=j+1;k<min(W,j+3);k++) S[0][k]='X';
            else{
                if(j+3>=W){
                    for(int i=0;i<H;i++){
                        if(j+2<W&&S[i][j+2]=='X') S[i][j+1]='X';
                    }
                }else{
                    if(j+1<W) S[aru][j+1]='X';
                    if(j+2<W) S[aru][j+2]='X';
                }
            }
        }
        
        for(int i=0;i<H;i++) cout<<S[i]<<"\n";
    }
}