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
vector<int> conn[400005];
int aa = 0;
void solve(int TC) {
    int n, k;
    cin >> n >> k;
    int deg[n + 5];
    for(int i = 0; i <= n; i++) conn[i].clear();
    for(int i = 0; i <= n; i++) deg[i] = 0;
    int t, tt;
    for(int i = 1; i < n; i++) {
        cin >> t >> tt;
        conn[t].pb(tt);
        conn[tt].pb(t);
        deg[t]++;
        deg[tt]++;
    }
    bool dead[n + 5];
    for(int i = 0; i <= n; i++) dead[i] = false;
    queue<pair<int, int>> cut, cut2;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1 || n == 1) {
            cut.push(mp(i, 1));
            //dead[i] = true;
        }
    }
    int ans = n;
    while(!cut.empty()) {
        auto now = cut.front();
        cut.pop();
        //if(dead[now.fi]) continue;
        if(now.se > k) break;
        //cout << now.fi << ' ' << now.se << '\n';
        ans--;
        dead[now.fi] = true;
        for(auto x: conn[now.fi]) {
            deg[x]--;
            if(deg[x] == 1) {
                cut.push(mp(x, now.se + 1));
                //dead[x] = true;
            }
        }
    }
    cout << ans << '\n';
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