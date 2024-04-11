#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;

int n,k;
int res = 0;
vector<int> G[N];

int dfs(int v, int p = -1){
    if(G[v].size() == 1) return 0;

    vector<int> cur;
    for(int nxt : G[v]){
        if(nxt != p) cur.push_back(dfs(nxt, v) + 1);
    }

    sort(cur.begin(), cur.end());

    while(cur.size() > 1 && cur[cur.size()-1] + cur[cur.size() - 2] > k){
        cur.pop_back();
        res ++;
    }

    return cur.back();

}

int main(){
    //for(int i = 0; i < N; i++) idx[i] = i;

    scanf("%d%d", &n, &k);
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(G[i].size() > 1){
            dfs(i);
            break;
        }
    }
    cout << res + 1 << endl;
}