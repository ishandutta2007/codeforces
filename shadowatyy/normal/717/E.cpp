#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N =  200020;

vector<int> odp;
vector<int> g[N];
int kol[N];


void dfs(int v, int o) {
    for (auto it : g[v]) {
        if (it == o)
            continue;
        kol[it] ^= 1;
        odp.pb(it);
        dfs(it, v);
        odp.pb(v);
        kol[v] ^= 1;
        if (kol[it] == 0) {
            odp.pb(it);
            odp.pb(v);
            kol[v] ^= 1;
            kol[it] ^= 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    bool czystop = 1;
    for (int i = 1; i <= n; i++) {
        cin>>kol[i];
        if (kol[i] == -1)
            kol[i] = 0;
        if (kol[i] == 0)
            czystop = false;
    }
    if (czystop) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0);
    if (kol[1] == 0) {
        odp.pb(g[1][0]);
        odp.pb(1);
        odp.pb(g[1][0]);
    }
    cout << 1 << " ";
    for (auto it : odp)
        cout << it << " ";
    return 0;
}