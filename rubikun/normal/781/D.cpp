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
const int mod=1000000007,MAX=505,INF=1<<30;
bitset<MAX> can[2][65][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        can[c][0][a][b]=1;
    }
    
    for(int t=1;t<65;t++){
        for(int k=0;k<2;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(can[k][t-1][i][j]){
                        can[k][t][i]|=can[!k][t-1][j];
                        //cout<<k<<" "<<t<<" "<<i<<" "<<j<<endl;
                    }
                }
            }
        }
    }
    
    ll ans=0;
    bitset<MAX> now;
    now[0]=1;
    bool f=0;
    for(int t=62;t>=0;t--){
        bitset<MAX> to;
        for(int i=0;i<N;i++) if(now[i]) to|=can[f][t][i];
        if(to.count()){
            ans+=(1LL<<t);
            now=to;
            f^=1;
        }
    }
    
    if(ans>1000000000000000000LL) cout<<-1<<endl;
    else cout<<ans<<endl;
    
}