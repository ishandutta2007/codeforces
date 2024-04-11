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
vector<int> G[MAX];
int dp1[MAX],dp2[MAX],depth[MAX],siz[MAX];

void DFS(int u){
    
    vector<pair<int,int>> A,B;
    
    for(int to:G[u]){
        depth[to]=depth[u]+1;
        DFS(to);
        siz[u]+=siz[to];
        
        A.push_back(mp(dp1[to],siz[to]));
        B.push_back(mp(dp2[to],siz[to]));
    }
    
    if(si(G[u])==0){
        siz[u]++;
        dp1[u]=1;
        dp2[u]=1;
        return;
    }
    
    if(depth[u]&1){
        int res1=-INF,res2=INF;
        int sum=0;
        for(int i=0;i<si(A);i++){
            sum+=A[i].fi-1;
            chmax(res1,A[i].fi);
        }
        for(int i=0;i<si(B);i++){
            chmin(res2,B[i].fi);
        }
        dp1[u]=sum+1;
        dp2[u]=res2;
    }else{
        int res1=INF,res2=-INF;
        int sum=0,sum2=0;
        for(int i=0;i<si(A);i++){
            sum+=A[i].se;
            chmin(res1,A[i].se-A[i].fi);
        }
        for(int i=0;i<si(B);i++){
            chmax(res2,B[i].se-B[i].fi);
            sum2+=B[i].se-B[i].fi;
        }
        dp1[u]=sum-res1;
        dp2[u]=sum-sum2;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
    }
    
    DFS(0);
    
    /*for(int i=0;i<N;i++){
        cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<endl;
    }*/
    
    cout<<dp1[0]<<" "<<dp2[0]<<endl;
}