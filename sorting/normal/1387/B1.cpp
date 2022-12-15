#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;

int n;
vector<int> adj[k_N];
int p[k_N];

int cnt[k_N], node[k_N];
vector<int> v;

int ans = 0;

void dfs(int x){
    for(int to: adj[x]){
        if(to == p[x]) continue;
        p[to] = x;
        dfs(to);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
        node[i] = i;

    for(int i = 1; i <= n; ++i){
        cnt[i] = adj[i].size();
        if(cnt[i] == 1) v.push_back(i);
    }

    p[1] = -1; 
    dfs(1);

    while(!v.empty()){
        int x = v.back();
        v.pop_back();

        if(node[x] == x){
            if(x != 1){
                swap(node[x], node[p[x]]);
                ans += 2;
            }
            else{
                swap(node[x], node[adj[x][0]]);
                ans += 2;
            }
        }

        if(x == 1) break;

        cnt[p[x]]--;
        if((cnt[p[x]] == 1 && p[x] != 1) || (cnt[p[x]] == 0 && p[x] == 1))
            v.push_back(p[x]);
    }

    cout << ans << "\n";
    for(int i = 1; i <= n; ++i)
        cout << node[i] << " ";
    cout << "\n";
}