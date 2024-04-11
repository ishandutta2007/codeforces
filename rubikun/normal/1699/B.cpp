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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<vector<int>> ans(H,vector<int>(W));
        for(int i=0;i<H/2;i++){
            for(int j=0;j<W/2;j++){
                if((i+j)&1){
                    ans[i*2+1][j*2]=ans[i*2][j*2+1]=1;
                }else{
                    ans[i*2][j*2]=ans[i*2+1][j*2+1]=1;
                }
            }
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}