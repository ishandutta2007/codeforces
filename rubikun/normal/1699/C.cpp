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
        int N;cin>>N;
        vector<int> P(N),pos(N);
        for(int i=0;i<N;i++){
            cin>>P[i];pos[P[i]]=i;
        }
        ll ans=1;
        
        int l=pos[0],r=pos[0];
        for(int i=1;i<N;i++){
            if(l<=pos[i]&&pos[i]<=r){
                int can=r-l+1-i;
                ans*=can;
                ans%=mod;
            }else{
                chmin(l,pos[i]);
                chmax(r,pos[i]);
            }
        }
        
        cout<<ans<<"\n";
    }
}