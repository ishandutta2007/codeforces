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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W,Q;cin>>H>>W>>Q;
    vector<vector<int>> ans(H,vector<int>(W));
    vector<pair<int,int>> X;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int h;cin>>h;h--;
            int x=ans[h][0];
            for(int j=0;j<W-1;j++) ans[h][j]=ans[h][j+1];
            ans[h].back()=x;
            X.push_back(mp(t,h));
        }
        if(t==2){
            int w;cin>>w;w--;
            int x=ans[0][w];
            for(int i=0;i<H-1;i++) ans[i][w]=ans[i+1][w];
            ans[H-1][w]=x;
            X.push_back(mp(t,w));
        }
        if(t==3){
            int h,w;cin>>h>>w;h--;w--;
            int x;cin>>x;
            ans[h][w]=x;
        }
    }
    
    reverse(all(X));
    
    for(auto a:X){
        if(a.fi==1){
            int h=a.se;
            int x=ans[h].back();
            for(int j=W-1;j>=1;j--) ans[h][j]=ans[h][j-1];
            ans[h][0]=x;
        }else{
            int w=a.se;
            int x=ans[H-1][w];
            for(int i=H-1;i>=1;i--) ans[i][w]=ans[i-1][w];
            ans[0][w]=x;
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}