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
        int N;cin>>N;
        string S;cin>>S;
        map<pair<int,int>,int> MA;
        int x=0,y=0;
        MA[{0,0}]=0;
        int mini=INF,ansl=-1,ansr=-1;
        
        for(int i=0;i<N;i++){
            if(S[i]=='U') y++;
            else if(S[i]=='D') y--;
            else if(S[i]=='L') x--;
            else if(S[i]=='R') x++;
            
            if(x==0&&y==0){
                if(i+1-MA[{x,y}]<mini){
                    mini=i+1-MA[{x,y}];
                    ansl=MA[{x,y}]+1;
                    ansr=i+1;
                }
            }else{
                if(MA[{x,y}]){
                    if(i+1-MA[{x,y}]<mini){
                        mini=i+1-MA[{x,y}];
                        ansl=MA[{x,y}]+1;
                        ansr=i+1;
                    }
                }
            }
            
            MA[{x,y}]=i+1;
        }
        
        if(mini==INF) cout<<-1<<endl;
        else cout<<ansl<<" "<<ansr<<endl;
    }
}