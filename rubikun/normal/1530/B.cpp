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

bool ng(vector<vector<int>> &ans){
    int H=si(ans),W=si(ans[0]);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int dh=-1;dh<=1;dh++){
                for(int dw=-1;dw<=1;dw++){
                    int toh=i+dh,tow=j+dw;
                    if(dh==0&&dw==0) continue;
                    if(toh<0||toh>=H||tow<0||tow>=W) continue;
                    if(ans[i][j]+ans[toh][tow]==2) return true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<vector<int>> ans(H,vector<int>(W));
        for(int j=0;j<W;j++){
            ans[0][j]=1;
            if(ng(ans)) ans[0][j]=0;
        }
        for(int i=1;i<H-1;i++){
            ans[i][W-1]=1;
            if(ng(ans)) ans[i][W-1]=0;
        }
        
        for(int j=W-1;j>=0;j--){
            ans[H-1][j]=1;
            if(ng(ans)) ans[H-1][j]=0;
        }
        
        for(int i=H-2;i>=1;i--){
            ans[i][0]=1;
            if(ng(ans)) ans[i][0]=0;
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}