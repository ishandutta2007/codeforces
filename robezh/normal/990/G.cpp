#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 200050, N = M;

int n, val[N];
vector<int> G[N];
vector<int> dvd[N];
ll cnt[N];
bool gd[N], vis[N];

int dfs(int v){
    vis[v] = true;
    int res = 0;
    for(int nxt : G[v]){
        if(!vis[nxt] && gd[nxt]) res += dfs(nxt);
    }
    return res + 1;
}

void get_cnt(int num){
    for(int x : dvd[num]) gd[x] = true;

    for(int x : dvd[num]){
        if(!vis[x]){
            int cur = dfs(x);
            cnt[num] += 1LL * cur * (cur + 1) / 2;
        }
    }

    for(int x : dvd[num]) gd[x] = vis[x] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val[i];
        dvd[val[i]].push_back(i);
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i < N; i++){
        for(int j = 2 * i; j < N; j += i){
            for(int x : dvd[j]) dvd[i].push_back(x);
        }
    }
    for(int i = 1; i < N; i++) get_cnt(i);

    for(int i = N-1; i >= 1; i--){
        for(int j = 2 * i; j < N; j += i) cnt[i] -= cnt[j];
    }
    for(int i = 0; i < N; i++) if(cnt[i] != 0) cout << i << " " << cnt[i] << endl;

}