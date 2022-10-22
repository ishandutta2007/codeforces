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
bool can;
vector<int> conn[200005];
int dist[200005];
int dfs(int now, int dep, int fa) {
    if(dist[now] <= dep) return 1;
    int cnt = 0;
    for(auto x: conn[now]) {
        if(x != fa) cnt += dfs(x, dep + 1, now);
    }
    if(cnt == 0) can = false;
    return cnt;
}
void solve(int TC) {
    can = true;
    int k, n, t, tt;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) conn[i].clear();
    for(int i = 0; i <= n; i++) dist[i] = -1;
    queue<int> bfs;
    
    for(int i = 0; i < k; i++) {
        cin >> t;
        dist[t] = 0;
        bfs.push(t);
    }
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
    }
    //bfs.push(mp(mp(1, 0), 1));
    //vector<int> idk;
    //int lsd = 0;
    while(!bfs.empty()) {
        //pair<pair<int, int>, bool> now = bfs.front();
        int now = bfs.front();
        bfs.pop();
        for(auto x: conn[now]) {
            if(dist[x] == -1) {
                dist[x] = dist[now] + 1;
                bfs.push(x);
            }
        }
        // idk.pb(now.fi.fi);
        // if(now.fi.se != lsd) {
        //     lsd = now.fi.se;
        //     for(auto x: idk) vi[x] = true;
        //     idk.clear();
        // }
        // //vi[now.fi] = true;
        // if(now.se && now.fi.fi != 1 && conn[now.fi.fi].size() == 1) {
        //     cout << "YES\n";
        //     return;
        // }
        // for(auto x: conn[now.fi.fi]) {
        //     if(!vi[x]) bfs.push(mp(mp(x, now.fi.se + 1), now.se));
        // }
    }
    // queue<pair<int, int>> bfs2;
    // bfs2.push(mp(1, 0));
    // while(!bfs2.empty()) {
    //     pair<int, int> now = bfs2.front();
    //     bfs2.pop();
    //     if(dist[now.fi] <= now.se) continue;
    //     dist[now.fi] = now.se;
    //     if(now.fi != 1 && conn[now.fi].size() == 1) {
    //         cout << "-1\n";
    //         return;
    //     }
    //     for(auto x: conn[now.fi]) {
    //         if(dist[x] > now.se + 1) bfs2.push(mp(x, now.se + 1));
    //     }
    // }
    int kk = dfs(1, 0, 1);
    cout << (can ? kk : -1) << '\n';
    //cout << "NO\n";
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