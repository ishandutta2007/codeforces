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
const ll INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        
        vector<vector<int>> sum(H,vector<int>(W+1));
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                sum[i][j+1]=sum[i][j]+(S[i][j]=='*');
            }
        }
        
        ll ans=0;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                for(int t=0;i+t<H;t++){
                    if(j-t<0) break;
                    if(j+t>=W) break;
                    
                    if(sum[i+t][j+t+1]-sum[i+t][j-t]==2*t+1) ans++;
                    else break;
                }
            }
        }
        
        cout<<ans<<endl;
    }
}