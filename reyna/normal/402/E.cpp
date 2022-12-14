//In the name of God
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int Maxn = 2015;
vector<int> in[Maxn];
vector<int> out[Maxn];
int vis[Maxn];
void dfs(int v,int s,vector<int> *al){
    if(vis[v] & s)
        return;
    vis[v] += s;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i];
        dfs(u,s,al);
    }
    return;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            int now;
            scanf("%d",&now);
            if(now){
                out[i].push_back(j);
                in[j].push_back(i);
            }
        }
    }
    dfs(0,1,out);
    dfs(0,2,in);
    for(int i = 0; i < n;i++){
        if(vis[i] ^ 3){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}