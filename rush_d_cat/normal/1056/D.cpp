#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;
int n;
vector<int> g[N];
int cnt[N],f[N];

int dfs(int u){
    if(g[u].size()==0)return cnt[u]=1;
    for(auto v:g[u]){
        dfs(v);cnt[u]+=cnt[v];
    }
    return cnt[u];
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int p; scanf("%d",&p);
        g[p].push_back(i);
    }
    dfs(1);

    for(int i=1;i<=n;i++)f[cnt[i]]++;
    for(int i=1;i<=n;i++)f[i]+=f[i-1];
    for(int i=1;i<=n;i++){
        int pos=lower_bound(f+1,f+1+n,i)-f;
        printf("%d ", pos);
    }
}