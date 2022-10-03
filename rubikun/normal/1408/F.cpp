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
    
    int N;cin>>N;
    if(N<=2){
        cout<<0<<endl;
        return 0;
    }
    
    vector<pair<int,int>> ans;
    
    for(int i=20;i>=0;i--){
        if(N&(1<<i)){
            for(int k=0;k<i;k++){
                for(int a=0;a<(1<<i);a++){
                    if(a&(1<<k)) continue;
                    ans.push_back(mp(a,a+(1<<k)));
                }
            }
            
            int D=N-(1<<i);
            
            for(int k=0;k<i;k++){
                for(int a=0;a<(1<<i);a++){
                    if(a&(1<<k)) continue;
                    ans.push_back(mp(D+a,D+a+(1<<k)));
                }
            }
            
            cout<<si(ans)<<"\n";
            for(auto x:ans) cout<<x.fi+1<<" "<<x.se+1<<"\n";
            
            return 0;
        }
    }
}