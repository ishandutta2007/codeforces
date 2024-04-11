#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt[256];
typedef long long li;
void solve();
int main(){

    ios_base::sync_with_stdio(false);
solve();
return 0;
}
const int MAXN = 200001;
vector<int> g[MAXN];
vector<int> obr[MAXN];
int ans[MAXN];
int pathup[MAXN];
int pathdown[MAXN];
int upSub[MAXN];
int downSub[MAXN];

void dfs(int v, int p, int pathUp, int pathDown){
    pathup[v] = pathUp;
    pathdown[v] = pathDown;
    for(int i = 0; i<g[v].size(); ++i){
        int to = g[v][i];
        if(to == p)
            continue;
        ++downSub[v];
        dfs(to, v, pathUp, pathDown + 1);
        downSub[v] += downSub[to];
        upSub[v] += upSub[to];
    }
    for(int i = 0; i <obr[v].size(); ++i){
        int to = obr[v][i];
        if(to == p)
            continue;
        ++upSub[v];
        dfs(to, v,  pathUp + 1, pathDown);
        downSub[v] += downSub[to];
        upSub[v] += upSub[to];
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n - 1;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].push_back(b);
        obr[b].push_back(a);
    }

    dfs(0, -1, 0 ,0);
    int mn = 1000000;
    for(int i =0 ; i < n;++i){
        ans[i] = upSub[0] - pathup[i] + pathdown[i];
        mn = min(mn, ans[i]);
    }

    cout<<mn<<endl;

    for(int i = 0; i < n; ++i){
        if(ans[i] == mn){
            cout<<i + 1 <<' ';
        }
    }


}