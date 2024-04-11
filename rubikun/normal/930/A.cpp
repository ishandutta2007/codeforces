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
int depth[MAX];

void DFS(int u){
    for(int to:G[u]){
        depth[to]=depth[u]+1;
        DFS(to);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=1;i<N;i++){
        int p;cin>>p;
        p--;
        G[p].push_back(i);
    }
    
    DFS(0);
    
    vector<int> cnt(N+1);
    for(int i=0;i<N;i++) cnt[depth[i]]++;
    
    int ans=0;
    
    for(int i=0;i<=N;i++) if(cnt[i]&1) ans++;
    
    cout<<ans<<endl;
}