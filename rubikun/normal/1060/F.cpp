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
const int mod=1000000007,MAX=55,INF=1<<30;
double pat[MAX][MAX],dp[MAX][MAX];

vector<int> G[MAX];
int siz[MAX];

void DFS(int u,int p){
    
    dp[u][0]=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        
        vector<double> dp2(siz[to]+1),dp3(siz[u]+siz[to]+1);
        
        for(int i=0;i<=siz[to];i++){
            for(int j=1;j<=siz[to];j++){
                if(j<=i) dp2[i]+=dp[to][j-1]*0.5;
                else dp2[i]+=dp[to][i];
            }
        }
        
        for(int i=0;i<=siz[u];i++){
            for(int j=0;j<=siz[to];j++){
                dp3[i+j]+=dp[u][i]*dp2[j]*pat[i+j][i]*pat[siz[u]+siz[to]-i-j][siz[to]-j];
            }
        }
        
        for(int i=0;i<=siz[u]+siz[to];i++) dp[u][i]=dp3[i];
        
        siz[u]+=siz[to];
    }
    
    siz[u]++;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    pat[0][0]=1;
    for(int i=1;i<MAX;i++){
        for(int j=0;j<=i;j++){
            if(j) pat[i][j]+=pat[i-1][j-1];
            pat[i][j]+=pat[i-1][j];
        }
    }
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    double al=1;
    for(int i=1;i<N;i++) al*=i;
    
    for(int t=0;t<N;t++){
        memset(dp,0,sizeof(dp));
        memset(siz,0,sizeof(siz));
        DFS(t,-1);
        cout<<fixed<<setprecision(25)<<dp[t][N-1]/al<<endl;
    }
}