#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;

int n,k;
ll p;
vector<int> G[N];
ll num[N], psum[N];

void dfs(int v, int p, int d){
    if(d != 0) num[n - d] ++;
    for(int nxt : G[v]){
        if(nxt == p) continue;
        dfs(nxt, v, d + 1);
    }
}

int main(){
    scanf("%d%d%I64d", &n, &k, &p);
    for(int i = 0; i < n-1; i++){
        int a, b; scanf("%d%d", &a, &b); a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 0);
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + num[i];

    int r = 1;
    ll res = 0;
    ll cur_sum = 0;
    for(int i = 1; i <= n; i++){
        while(r <= n && 1LL * (r - i) * num[r] + cur_sum <= p){
            cur_sum += 1LL * (r - i) * num[r];
            r++;
        }
        ll cur = psum[r-1] - psum[i-1] + (r == n + 1 ? 0 : (p - cur_sum) / (r - i));
        res = max(cur, res);
        cur_sum -= psum[r-1] - psum[i];
    }
    cout << min((ll)k, res) << endl;
}