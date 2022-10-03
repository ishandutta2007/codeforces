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
        vector<vector<int>> ans(H,vector<int>(W));
        bool ok=true;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                int a;cin>>a;
                if(i==0&&j==0){
                    if(a>=3) ok=false;
                    ans[i][j]=2;
                }
                else if(i==0&&j==W-1){
                    if(a>=3) ok=false;
                    ans[i][j]=2;
                }
                else if(i==H-1&&j==0){
                    if(a>=3) ok=false;
                    ans[i][j]=2;
                }
                else if(i==H-1&&j==W-1){
                    if(a>=3) ok=false;
                    ans[i][j]=2;
                }
                else if(i==0||i==H-1){
                    if(a>=4) ok=false;
                    ans[i][j]=3;
                }
                else if(j==0||j==W-1){
                    if(a>=4) ok=false;
                    ans[i][j]=3;
                }
                else{
                    if(a>=5) ok=false;
                    ans[i][j]=4;
                }
            }
        }
        
        if(!ok) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    }
}