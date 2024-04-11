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
const int mod=998244353,MAX=200005,INF=1<<30;

vector<int> G[MAX];
set<int> SE[MAX];
int A[MAX];
int dp[MAX];
int fl[MAX];

void solve(int u,int p){
    SE[u].insert(A[u]);
    bool ok=true;
    int sum=0;
    for(int to:G[u]){
        if(to==p) continue;
        solve(to,u);
        sum+=dp[to];
        if(!ok) continue;
        if(si(SE[u])<si(SE[to])){
            swap(SE[u],SE[to]);
            
            for(int x:SE[to]){
                if(SE[u].count(x^fl[to]^fl[u])){
                    ok=false;
                    break;
                }
            }
            if(!ok) continue;
            
            for(int x:SE[to]){
                SE[u].insert(x^fl[to]^fl[u]^A[u]);
            }
            
            fl[u]=A[u]^fl[to];
        }else{
            for(int x:SE[to]){
                if(SE[u].count(x^fl[to]^fl[u])){
                    ok=false;
                    break;
                }
            }
            if(!ok) continue;
            
            for(int x:SE[to]){
                SE[u].insert(x^fl[to]^fl[u]^A[u]);
            }
        }
        
        /*
        for(int x:SE[to]){
            if(SE[u].count(x)){
                ok=false;
            }
        }
        if(!ok) break;
        
        for(int x:SE[to]){
            SE[u].insert(x^A[u]);
        }
         */
    }
    
    if(ok){
        dp[u]=sum;
    }else{
        dp[u]=sum+1;
        SE[u].clear();
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve(0,-1);
    
    cout<<dp[0]<<endl;
}