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
const int mod=998244353,MAX=400005;
const ll INF=1LL<<60;

const int D=200000;
vector<pair<int,int>> G[MAX];
bool used[MAX];
int ans[MAX];
int color[MAX];

void DFS(int u,int c){
    //cout<<u<<" "<<c<<endl;
    for(int i=0;i<si(G[u]);){
        if(used[G[u][i].se]){
            swap(G[u][i],G[u].back());
            G[u].pop_back();
        }else{
            int a=G[u][i].fi,b=G[u][i].se;
            ans[b]=c;
            color[u]+=c;
            color[a]+=c;
            used[b]=true;
            swap(G[u][i],G[u].back());
            G[u].pop_back();
            DFS(a,c*(-1));
            return;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(mp(D+b,i));
        G[D+b].push_back(mp(a,i));
    }
    
    for(int i=0;i<2*D;i++){
        while(si(G[i])){
            if(color[i]<=0) DFS(i,1);
            else DFS(i,-1);
        }
    }
    
    for(int i=0;i<N;i++){
        if(ans[i]==1) cout<<'b';
        else cout<<'r';
    }
    cout<<endl;
}