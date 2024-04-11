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
        vector<vector<char>> S(H,vector<char>(W,'B'));
        S[0][0]='W';
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout<<S[i][j];
            }
            cout<<"\n";
        }
    }
}