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
const int mod=998244353,MAX=300005,INF=1<<30;

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
        if(S[0][0]=='1'){
            cout<<-1<<"\n";
            continue;
        }
        vector<vector<int>> ans;
        for(int i=H-1;i>=0;i--){
            for(int j=W-1;j>=0;j--){
                if(j){
                    if(S[i][j]=='1') ans.push_back({i,j-1,i,j});
                }else{
                    if(S[i][j]=='1') ans.push_back({i-1,j,i,j});
                }
            }
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans){
            for(int b:a) cout<<b+1<<" ";
            cout<<"\n";
        }
    }
}