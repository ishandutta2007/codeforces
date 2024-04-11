#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int K;cin>>K;
    cout<<3<<" "<<3<<"\n";
    vector<vector<int>> ans(3,vector<int>(3,(1<<17)));
    ans[0][1]=0;
    ans[2][2]=0;
    
    ans[0][0]+=K;
    ans[0][1]+=K;
    ans[1][1]+=K;
    ans[1][2]+=K;
    ans[2][2]+=K;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}