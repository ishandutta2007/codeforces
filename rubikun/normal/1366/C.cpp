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
        vector<vector<int>> S(H,vector<int>(W));
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++) cin>>S[i][j];
        }
        
        int ans=0;
        
        int X=(H-1)+(W-1)+1;
        
        vector<int> cnt0(X),cnt1(X);
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]==0){
                    cnt0[min(i+j,X-1-(i+j))]++;
                }else cnt1[min(i+j,X-1-(i+j))]++;
            }
        }
        
        for(int i=0;i<X/2;i++){
            ans+=min(cnt0[i],cnt1[i]);
        }
        
        cout<<ans<<"\n";
    }
}