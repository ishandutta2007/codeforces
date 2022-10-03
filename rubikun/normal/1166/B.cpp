#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int K;cin>>K;
    int left=-1,right=-1;
    for(int i=5;i*i<=K;i++){
        if(K%i==0){
            left=i;
            right=K/i;
            break;
        }
    }
    string S="aiueo";
    
    if(left==-1) cout<<-1<<endl;
    else{
        vector<vector<int>> A(left,vector<int>(right));
        
        for(int i=0;i<left;i++){
            for(int j=0;j<right;j++){
                A[i][j]=(i+j)%5;
            }
        }
        
        for(int i=0;i<left;i++){
            for(int j=0;j<right;j++){
                cout<<S[A[i][j]];
            }
        }
        
        cout<<endl;
    }
}