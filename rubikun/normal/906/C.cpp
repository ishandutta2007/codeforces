#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=25,INF=1<<30;
bool edge[MAX][MAX],ok[1<<22];
int uni[MAX];
int dp[1<<22];
vector<int> need[1<<22];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(edge[i][j]) uni[i]|=(1<<j);
        }
    }
    
    for(int bit=1;bit<(1<<N);bit++){
        if(__builtin_popcount(bit)==1) ok[bit]=1;
        if(!ok[bit]) continue;
        
        for(int to=0;to<N;to++){
            if(bit&(1<<to)) continue;
            
            if((uni[to]&bit)==bit) ok[bit|(1<<to)]=1;
        }
    }
    
    for(int bit=1;bit<(1<<N);bit++){
        if(ok[bit]) dp[bit]=0;
        else dp[bit]=INF;
    }
    
    for(int bit=1;bit<(1<<N);bit++){
        for(int i=0;i<N;i++){
            if(!(bit&(1<<i))) continue;
            
            if(chmin(dp[bit|(uni[i])],dp[bit]+1)){
                need[bit|(uni[i])]=need[bit];
                need[bit|(uni[i])].push_back(i);
            };
        }
        //need[bit].clear();
    }
    
    cout<<dp[(1<<N)-1]<<endl;
    for(int a:need[(1<<N)-1]) cout<<a+1<<" ";
    cout<<endl;
}