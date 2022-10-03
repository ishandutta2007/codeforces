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
    pair<int,int> start,goal;
    vector<vector<char>> S(H+2,vector<char>(W+2,'#'));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i+1][j+1];
            if(S[i+1][j+1]=='S') start={i+1,j+1};
            if(S[i+1][j+1]=='E') goal={i+1,j+1};
        }
    }
    string T;cin>>T;
    
    vector<int> P={0,1,2,3};
    int ans=0;
    
    do{
        int hnow=start.first,wnow=start.second;
        
        for(int i=0;i<T.size();i++){
            hnow+=dh[P[T[i]-'0']];
            wnow+=dw[P[T[i]-'0']];
            
            if(make_pair(hnow,wnow)==goal){
                ans++;
                break;
            }
            
            if(S[hnow][wnow]=='#'){
                break;
            }
        }
    }while(next_permutation(all(P)));
    
    cout<<ans<<endl;
}