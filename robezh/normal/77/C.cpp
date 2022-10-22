#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef long long ll;
typedef pair<ll, ll> P;

int n, r;
vector<int> G[N];
int a[N];

P dfs(int v, int p) {
    vector<ll> lar;
    ll sum = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        P p = dfs(nxt, v);
        lar.push_back(p.first);
        sum += p.second;
    }
    sort(lar.begin(), lar.end(), greater<>());
    while(!lar.empty() && lar.back() == 0) lar.pop_back();
    if(p != -1) a[v]--;
    ll res = 0, res2 = 0;
    if(a[v] <= lar.size()) {
        for(int i = 0; i < a[v]; i++) res += lar[i];
        res += a[v];
//        return {res, 0};
    }
    else {
        for(ll x : lar) res += x;
        res += lar.size();
        a[v] -= lar.size();
        ll take = min(1LL * a[v], sum);
        res += take * 2;
        res2 = a[v] - take;
    }
    if(p != -1) res++;
//    cout << v + 1 << ": " << res << ", " << res2 << endl;
    return {res, res2};
}



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> r; r--;
    cout << dfs(r, -1).first << endl;
}