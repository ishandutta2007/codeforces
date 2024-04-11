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
        bool f=true,g=true;
        for(int i=0;i<H;i++){
            cin>>S[i];
            for(int j=0;j<W;j++){
                if(S[i][j]=='R'){
                    if((i+j)&1) f=false;
                    else g=false;
                }else if(S[i][j]=='W'){
                    if((i+j)&1) g=false;
                    else f=false;
                }
            }
        }
        
        if(f){
            cout<<"YES\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    if((i+j)&1) S[i][j]='W';
                    else S[i][j]='R';
                }
                cout<<S[i]<<"\n";
            }
            continue;
        }
        
        if(g){
            cout<<"YES\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    if((i+j)&1) S[i][j]='R';
                    else S[i][j]='W';
                }
                cout<<S[i]<<"\n";
            }
            continue;
        }
        
        cout<<"NO\n";
    }
}