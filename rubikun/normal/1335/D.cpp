#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        vector<string> S(9);
        for(int i=0;i<9;i++){
            cin>>S[i];
            for(int j=0;j<9;j++){
                if(S[i][j]=='1') S[i][j]='2';
            }
            cout<<S[i]<<"\n";
        }
    }
}