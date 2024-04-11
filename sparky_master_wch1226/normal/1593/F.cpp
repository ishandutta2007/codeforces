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
void gay(int TC) {cout << "Case #" << TC << ": ";}
pair<int, pair<int, int>> dp[45][45][45][45];
void solve(int TC) {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    s = "." + s;
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0].fi = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int na = 0; na < a; na++) {
                for(int nb = 0; nb < b; nb++) {
                    if(dp[i][j][na][nb].fi == 0) continue;
                    int nna = (na * 10 + s[i + 1] - '0') % a;
                    int nnb = (nb * 10 + s[i + 1] - '0') % b;
                    if(dp[i + 1][j + 1][nna][nb].fi == 0) {
                        dp[i + 1][j + 1][nna][nb] = mp(1, mp(na, nb));
                    }
                    if(dp[i + 1][j][na][nnb].fi == 0) {
                        dp[i + 1][j][na][nnb] = mp(-1, mp(na, nb));
                    }
                }
            }
        }
    }
    vector<int> tries;
    for(int i = n / 2; i >= 1; i--) {
        tries.pb(i);
        if(n - i != i) tries.pb(n - i);
    }
    for(auto x: tries) {
        int aa = 0, bb = 0, xx = x;
        if(dp[n][xx][0][0].fi != 0) {
            string ans = "";
            int i = n;
            while(i > 0) {
                if(dp[i][xx][aa][bb].fi == 1) {
                    ans = "R" + ans;
                    pair<int, int> tmp;
                    tmp = dp[i][xx][aa][bb].se;
                    aa = tmp.fi;
                    bb = tmp.se;
                    xx--;
                }
                else {
                    ans = "B" + ans;
                    pair<int, int> tmp;
                    tmp = dp[i][xx][aa][bb].se;
                    aa = tmp.fi;
                    bb = tmp.se;
                }
                i--;
            }
            cout << ans << '\n';
            return;
        }
        
    }
    cout << "-1\n";
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