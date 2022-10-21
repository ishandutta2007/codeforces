#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n;
vector<int> G[N];

bool vis[N];
vector<int> visa;

void dfs(int v){
    vis[v] = true;
    visa.push_back(v);

    for(int nxt : G[v]){
        if(!vis[nxt]) dfs(nxt);
    }
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        for(int j = 2 * i; j <= n; j += i){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }

    ll f_res = 0;

    for(int i = 2; i <= n; i++){
        if(vis[i]) continue;

        visa.clear();
        dfs(i);
        ll res = 0;
        for(int v : visa){
            for(int nxt : G[v]){
                res += max(nxt, v) / min(nxt, v);
            }
        }
        f_res = max(f_res, res * 2);
    }
    cout << f_res << endl;



}