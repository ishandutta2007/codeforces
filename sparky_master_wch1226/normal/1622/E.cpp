#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18

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
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    int ans[m + 5];
    int best = -1;
    string grid[n + 5];
    int exp[n + 5];
    for(int i = 0; i < n; i++) cin >> exp[i];
    for(int i = 0; i < n; i++) cin >> grid[i];
    for(int i = 0; i < (1 << n); i++) {
        pair<int, int> tmp[m + 5];
        for(int j = 0; j < m; j++) tmp[j] = mp(0, j);
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(grid[k][j] == '1') {
                    if(i & (1 << k)) tmp[j].fi++;
                    else tmp[j].fi--;
                }
            }
        }
        sort(tmp, tmp + m);
        int tc = 0;
        int tarr[n + 5];
        for(int j = 0; j < n; j++) tarr[j] = 0;
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(grid[k][tmp[j].se] == '1') {
                    tarr[k] += j + 1;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            tc += abs(tarr[j] - exp[j]);
        }
        if(tc > best) {
            best = tc;
            for(int j = 0; j < m; j++) ans[tmp[j].se] = j + 1;
        }
    }
    for(int i = 0; i < m; i++) cout << ans[i] << ' ';
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