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
        int n,k;cin>>n>>k;
        vector<vector<int>> ans(n,vector<int>(n));
        
        if(k%n==0) cout<<0<<"\n";
        else cout<<2<<"\n";
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(k){
                    ans[i][(i+j)%n]=1;
                    k--;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
        
        
    }
}