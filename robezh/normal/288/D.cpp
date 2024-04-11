#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 80005;

int n;
vector<int> G[N];
ll res = 0;
int sub[N];

ll C(int x){
    return 1LL * x * (x - 1) / 2;
}

int dfs(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v]){
        if(nxt != p) sub[v] += dfs(nxt, v);
    }
    return sub[v];
}

void ndfs(int v, int p){
    ll num1 = 1LL * sub[v] * (n - sub[v]);
    ll num2 = C(sub[v]);
    for(int nxt : G[v]){
        if(nxt != p){
            num2 -= C(sub[nxt]);
            ndfs(nxt, v);
        }
    }
    res -= 2 * num1 * num2 + num2 * num2;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b); a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    res = (1LL * n * (n-1) / 2) * (1LL * n * (n-1) / 2);
    dfs(0, -1);
    ndfs(0, -1);
    cout << res << endl;
}