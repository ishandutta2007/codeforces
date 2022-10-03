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
int N,M,K;
vector<pair<int,int>> G[MAX];

vector<int> cnt[10][10];

map<vector<int>,int> MA;

vector<int> sum;

int ans=0;

void DFS(int now){
    if(now==K+1||now==7){
        MA[sum]++;
        return;
    }
    
    for(int i=1;i<=now;i++){
        bool ok=true;
        
        for(int j:cnt[now][i]){
            sum[j]++;
            if(sum[j]>=2) ok=false;
        }
        
        if(ok) DFS(now+1);
        
        for(int j:cnt[now][i]){
            sum[j]--;
        }
    }
}

void DFS2(int now){
    if(now==K+1){
        if(MA.count(sum)) ans+=MA[sum];
        return;
    }
    
    for(int i=1;i<=now;i++){
        bool ok=true;
        
        for(int j:cnt[now][i]){
            sum[j]--;
            if(sum[j]<0) ok=false;
        }
        
        if(ok) DFS2(now+1);
        
        for(int j:cnt[now][i]){
            sum[j]++;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>K;
    sum.resize(N);
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(mp(c,b));
    }
    
    for(int i=0;i<N;i++) sort(all(G[i]));
    
    for(int i=1;i<=K;i++){
        for(int j=1;j<=i;j++){
            for(int k=0;k<N;k++){
                if(si(G[k])==i){
                    cnt[i][j].push_back(G[k][j-1].se);
                }
            }
        }
    }
    
    vector<int> ok(N,1);
    
    if(K<=6){
        DFS(1);
        
        cout<<MA[ok]<<endl;
    }else{
        DFS(1);
        
        for(int i=0;i<N;i++) sum[i]=1;
        
        DFS2(7);
        
        cout<<ans<<endl;
    }
    
}