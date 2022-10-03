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
const int mod=1000000007,MAX=5002,INF=(1<<30)-5;
int N;
int siz[MAX];
vector<vector<int>> dp0(MAX),dp1(MAX);
int cost[MAX][2];

vector<int> G[MAX];

void make(int u){
    for(int to:G[u]){
        make(to);
        siz[u]+=siz[to];
    }
    siz[u]++;
}

void solve(int u){
    
    vector<vector<int>> pre(siz[u]+1,vector<int>(2,INF));
    
    pre[0][0]=0;
    pre[1][0]=cost[u][0];
    pre[0][1]=cost[u][1];
    pre[1][1]=cost[u][1];
    
    int i=0,sum=1;
    
    for(int to:G[u]){
        solve(to);
        
        for(int j=sum+siz[to];j>=0;j--){
            for(int k=max(0,j-sum);k<=siz[to];k++){
                if(j-k<0) break;
                chmin(pre[j][0],pre[j-k][0]+dp0[to][k]);
                chmin(pre[j][1],pre[j-k][1]+dp0[to][k]);
                chmin(pre[j][1],pre[j-k][1]+dp1[to][k]);
            }
        }
        
        i++;
        sum+=siz[to];
        
        dp0[to].clear();
        dp1[to].clear();
    }
    
    for(int j=0;j<=siz[u];j++){
        dp0[u].push_back(pre[j][0]);
        dp1[u].push_back(pre[j][1]);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    int M;cin>>M;
    
    for(int i=0;i<N;i++){
        int a,b,c;
        if(i==0){
            cin>>a>>b;
            cost[i][0]=a;
            cost[i][1]=a-b;
        }else{
            cin>>a>>b>>c;
            c--;
            G[c].push_back(i);
            cost[i][0]=a;
            cost[i][1]=a-b;
        }
    }
    
    make(0);
    solve(0);
    
    for(int i=0;i<=N;i++){
        if(dp0[0][i]<=M||dp1[0][i]<=M) continue;
        else{
            cout<<i-1<<endl;
            return 0;
        }
    }
    
    cout<<N<<endl;
                  
                  
}