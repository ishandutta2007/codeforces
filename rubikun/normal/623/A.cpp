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
const int mod=1000000007,MAX=505,INF=1<<30;
bool aru[MAX][MAX];

vector<int> G[MAX];
int color[MAX];
void solve(int u){
    for(int to:G[u]){
        if(color[to]){
            if(color[u]==color[to]){
                cout<<"No\n";
                exit(0);
            }
        }else{
            color[to]=3-color[u];
            solve(to);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        aru[a][b]=aru[b][a]=true;
    }
    
    int K=0;
    vector<int> use;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(!aru[i][j]){
                G[i].push_back(j);
                G[j].push_back(i);
                use.push_back(i);
                use.push_back(j);
                K++;
            }
        }
    }
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    for(int a:use){
        if(color[a]==0){
            color[a]=1;
            solve(a);
        }
    }
    
    int x=0,y=0;
    for(int a:use){
        if(color[a]==1) x++;
        if(color[a]==2) y++;
    }
    
    if(x*y==K){
        cout<<"Yes\n";
        string ans(N,'b');
        for(int a:use){
            if(color[a]==1) ans[a]='a';
            if(color[a]==2) ans[a]='c';
        }
        cout<<ans<<"\n";
    }else{
        cout<<"No\n";
    }
}