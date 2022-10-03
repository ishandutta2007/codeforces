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
const int mod=1000000007,MAX=55,INF=1<<28;
vector<int> G[MAX],belong[MAX];
int dis[MAX][MAX];
int dp[MAX][MAX];
int cnt[MAX];
bool leaf[MAX];

void pre(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        pre(to,u);
        cnt[u]+=cnt[to];
    }
}

void bel(int u,int p,int ro){
    belong[ro].push_back(u);
    for(int to:G[u]){
        if(to==p) continue;
        bel(to,u,ro);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        dis[a][b]=c;
        dis[b][a]=c;
    }
    
    for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++) chmin(dis[i][j],dis[i][k]+dis[k][j]);
    
    int s;cin>>s;s--;
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int x;cin>>x;x--;
        cnt[x]++;
    }
    
    pre(s,-1);
    for(int ch:G[s]){
        bel(ch,s,ch);
    }
    
    for(int i=0;i<N;i++){
        if(si(G[i])==1) leaf[i]=true;
    }
    
    for(int x=1;x<=M;x++){
        for(int u=0;u<N;u++){
            if(!leaf[u]) continue;
            int left=0,right=INF;
            while(right-left>1){
                int mid=(left+right)/2;
                int sum=0;
                for(int v=0;v<N;v++){
                    if(u==v) continue;
                    if(!leaf[v]) continue;
                    for(int y=x;y>=0;y--){
                        if(dp[v][x-y]+dis[u][v]>=mid){
                            sum+=y;
                            break;
                        }
                    }
                }
                if(sum>=x) left=mid;
                else right=mid;
            }
            dp[u][x]=left;
        }
    }
    
    int left=0,right=INF;
    
    while(right-left>1){
        int mid=(left+right)/2;
        bool ok=true;
        for(int ch:G[s]){
            int sum=0;
            for(int v:belong[ch]){
                if(!leaf[v]) continue;
                for(int y=cnt[ch];y>=0;y--){
                    if(dp[v][M-y]+dis[s][v]>=mid){
                        sum+=y;
                        break;
                    }
                }
            }
            if(sum<cnt[ch]) ok=false;
        }
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}