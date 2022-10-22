#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
const int mod = 998244353;
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
int ncr_pre[5005][5005];
int ncr(int n, int r) {
    if(n < r) return 0;
    // cerr << ncr_pre[n][r] << '\n';
    return ncr_pre[n][r];
}
void solve(int TC) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 1;
    int tc = 0;
    for(auto x: s) tc += x - '0';
    if(tc < k || k == 0) {
        cout << "1\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(i != 0 && s[i - 1] != '1') continue;
        int j = i - 1, id = -1, cnt = 0;
        while(cnt <= k && !(j == n - 1 || (cnt == k && s[j + 1] == '1'))) {
            j++;
            cnt += s[j] - '0';
            if(s[j] == '1' && id == -1) id = j;
        }
        if(cnt == 0) continue;
        int len = j - i + 1;
        int len2 = j - id;
        ans += ncr(len, cnt) - ncr(len2, cnt - 1);
        ans %= mod;
        // cerr << i << ' ' << ans << '\n';
    }   
    ans = ans + mod;
    ans %= mod;
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 0; i <= 5000; i++) {
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) ncr_pre[i][j] = 1;
            else ncr_pre[i][j] = ncr_pre[i - 1][j] + ncr_pre[i - 1][j - 1];
            ncr_pre[i][j] %= mod;
        }
    }
    for(int i = 1; i <= t; i++) solve(i);
    
    return 0;
}