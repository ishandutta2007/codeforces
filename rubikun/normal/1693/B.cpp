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
ll L[MAX],R[MAX];
ll sum[MAX];
ll ans=0;

void solve(int u){
    for(int to:G[u]){
        solve(to);
        sum[u]+=sum[to];
    }
    if(sum[u]<L[u]){
        ans++;
        sum[u]=R[u];
    }else if(sum[u]>R[u]){
        sum[u]=R[u];
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            L[i]=R[i]=sum[i]=0;
        }
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G[p].push_back(i);
        }
        
        for(int i=0;i<N;i++){
            cin>>L[i]>>R[i];
        }
        
        ans=0;
        
        solve(0);
        
        cout<<ans<<"\n";
    }
}