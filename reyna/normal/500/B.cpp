//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 320;
vector<int> ans[Maxn];
int com[Maxn];
int cnt[Maxn];
int mat[Maxn][Maxn];
int per[Maxn];
int vis[Maxn];
int n;
int now = 0;
int dfs(int v){
    if(vis[v])
        return 0;
    vis[v] = true;
    com[v] = now;
    ans[now].push_back(per[v]);
    for(int i = 0; i < n;i++){
        if(mat[v][i])
            dfs(i);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> per[i];
        per[i]--;
    }
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n;j++){
            char now;
            cin >> now;
            if(now - '0')
                mat[i][j] = 1;
        }
    for(int i = 0; i < n;i++){
        if(!vis[i]){
            dfs(i);
            now++;
        }
    }
    for(int i = 0; i < n;i++){
        sort(ans[i].begin(),ans[i].end());
    }
    for(int v = 0; v < n;v++){
        cout << ans[com[v]][cnt[com[v]]]+1 << " ";
        cnt[com[v]]++;
    }
    cout << endl;
    return 0;
}