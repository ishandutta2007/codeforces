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
const int mod=1000000007,MAX=110005,INF=1<<30;
const int K=1<<12;
bitset<K> dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    vector<vector<int>> S(M,vector<int>(N));
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
        for(int bit=0;bit<(1<<M);bit++){
            if(bit&(1<<i)){
                dp[i][bit]=true;
            }else{
                dp[i][bit]=false;
            }
        }
    }
    int now=M;
    while(Q--){
        int t;cin>>t;
        int a,b;cin>>a>>b;a--;b--;
        if(t==1){
            dp[now]=dp[a]|dp[b];
            now++;
        }
        if(t==2){
            dp[now]=dp[a]&dp[b];
            now++;
        }
        if(t==3){
            vector<int> id(M);
            iota(all(id),0);
            sort(all(id),[&](int x,int y){
                return S[x][b]<S[y][b];
            });
            
            int ans=(1<<M)-1;
            
            int bi=(1<<M)-1;
            for(int i=0;i<=M;i++){
                int S=0;
                if(dp[a][bi]){
                    for(int j=i;j<M;j++) S|=(1<<id[j]);
                }else{
                    for(int j=0;j<i;j++) S|=(1<<id[j]);
                }
                ans&=S;
                if(i<M) bi^=(1<<id[i]);
                
                //cout<<ans<<endl;
            }
            for(int i=0;i<M;i++){
                if(ans&(1<<i)){
                    cout<<S[i][b]<<"\n";
                    break;
                }
            }
        }
    }
}