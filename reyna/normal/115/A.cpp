//In the name of God
// Silver Soul!!!
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 1e5 + 1e3;
vector<int> al[Maxn];
vector<int> to_dfs;
int dfs(int v,int p = -1){
    int ret = 0;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i];
        if(u == p)
            continue;
        ret = max(ret,dfs(u,v));
    }
    return ret + 1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int v;
        cin >> v;
        --v;
        if(v == -2)
            to_dfs.push_back(i);
        else
            al[v].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < to_dfs.size();i++)
        ans = max(ans,dfs(to_dfs[i]));
    cout << ans << endl;
    return 0;
}