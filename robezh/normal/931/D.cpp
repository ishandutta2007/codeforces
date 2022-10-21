#include <bits/stdc++.h>
using namespace std;

int n,a;
vector<int> G[100500];
int cnt[100500], dep[100500];
bool vis[100500];

void dfs(int v, int d){
    vis[v] = true;
    cnt[d] ++;
    //cout << "add " << d << endl;
    for(int nxt : G[v]){
        //cout << "search" << endl;
        if(!vis[nxt]){

            dfs(nxt, d+1);

        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){

        cin >> a;
        a--;
        G[a].emplace_back(i);
    }
    //cout << G[0].size() << endl;
    fill(vis, vis+100500, false);
    fill(cnt, cnt+100500, 0);
    dfs(0,0);
    int res = 0;
    for(int i = 0; i < 100500; i++){
        //cout << cnt[i] << endl;
        if(cnt[i] % 2 == 1) res++;
    }
    cout << res;

}