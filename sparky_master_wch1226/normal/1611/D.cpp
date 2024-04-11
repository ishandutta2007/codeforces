#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long

using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int root;
vector<int> conn[200005];
int ans[200005];
int dist[200005];
int req[200005];
int fa[200005];
int idk[200005];
int n, t;
void dfs(int now, int f) {
    fa[now] = f;
    for(auto x: conn[now]) {
        if(x != f) dfs(x, now);
    }
    return;
}
void solve(int TC) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) conn[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> t;
        idk[i] = t;
        if(t == i) root = i;
        else {
            conn[i].pb(t);
            conn[t].pb(i);
        }
    }
    for(int i = 1; i <= n; i++) cin >> req[i];
    dfs(root, root);
    for(int i = 1; i <= n; i++) {
        dist[i] = -1;
    }
    dist[root] = 0;
    if(req[1] != root) {
        cout << "-1\n";
        return;
    }
    for(int i = 2; i <= n; i++) {
        if(dist[fa[req[i]]] == -1) {
            cout << "-1\n";
            return;
        }
        dist[req[i]] = i;
        if(idk[req[i]] == fa[req[i]]) ans[req[i]] = i - dist[fa[req[i]]];
        else ans[fa[req[i]]] = i - dist[fa[req[i]]];
    }
    ans[root] = 0;
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}