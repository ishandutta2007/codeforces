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
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        bool Aexi=false,edgeexi=false,Pexi=false,allexi=false,cornerexi=false,edgeallexi=false;
        //edgeexi...3 allexi...2 cornerexi... 2 edgeallexi... 1
        for(int i=0;i<H;i++){
            cin>>S[i];
            for(int j=0;j<W;j++){
                if(S[i][j]=='A') Aexi=true;
                else Pexi=true;
                
                if(i==0||i==H-1){
                    if(S[i][j]=='A') edgeexi=true;
                }
                
                if(j==0||j==W-1){
                    if(S[i][j]=='A') edgeexi=true;
                }
            }
        }
        
        if(S[0][0]=='A') cornerexi=true;
        if(S[0][W-1]=='A') cornerexi=true;
        if(S[H-1][0]=='A') cornerexi=true;
        if(S[H-1][W-1]=='A') cornerexi=true;
        
        for(int i=1;i<H-1;i++){
            if(allexi) break;
            allexi=true;
            for(int j=0;j<W;j++){
                if(S[i][j]=='P') allexi=false;
            }
        }
        
        for(int j=1;j<W-1;j++){
            if(allexi) break;
            allexi=true;
            for(int i=0;i<H;i++){
                if(S[i][j]=='P') allexi=false;
            }
        }
        
        if(!edgeallexi){
            edgeallexi=true;
            for(int j=0;j<W;j++){
                if(S[0][j]=='P') edgeallexi=false;
            }
        }
        
        if(!edgeallexi){
            edgeallexi=true;
            for(int j=0;j<W;j++){
                if(S[H-1][j]=='P') edgeallexi=false;
            }
        }
        
        if(!edgeallexi){
            edgeallexi=true;
            for(int i=0;i<H;i++){
                if(S[i][0]=='P') edgeallexi=false;
            }
        }
        
        if(!edgeallexi){
            edgeallexi=true;
            for(int i=0;i<H;i++){
                if(S[i][W-1]=='P') edgeallexi=false;
            }
        }
        
        if(!Pexi) cout<<0<<endl;
        else if(!Aexi) cout<<"MORTAL"<<endl;
        else if(edgeallexi) cout<<1<<endl;
        else if(cornerexi) cout<<2<<endl;
        else if(allexi) cout<<2<<endl;
        else if(edgeexi) cout<<3<<endl;
        else cout<<4<<endl;
    }
}