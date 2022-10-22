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
const int mod = 1000000007;
void solve(int TC) {
    int n, m, bx, by, cx, cy, p;
    cin >> n >> m >> bx >> by >> cx >> cy >> p;
    int cnt = 0;
    int xx = bx, yy = by, dx = 1, dy = 1;
    int x = 1, y = 1;
    int nowp = 1, ans = 0;
    int pclean = p * inv(100, mod) % mod;
    int pnotclean = (100 - p) * inv(100, mod) % mod;
    while(cnt == 0 || xx != bx || yy != by || (dx != x && xx != 1 && xx != n) || (dy != y && yy != 1 && yy != m)) {
        if(bx == 1 && x == -1) x = 1;
        if(bx == n && x == 1) x = -1;
        if(by == 1 && y == -1) y = 1;
        if(by == m && y == 1) y = -1;
        if(bx == cx || by == cy) {
            ans += cnt * nowp % mod * pclean % mod;
            nowp *= pnotclean;
            nowp %= mod;
            ans %= mod;
        }
        cnt++;
        bx += x;
        by += y;
    }
    int aans = (nowp * cnt % mod + ans) % mod * inv((mod + 1 - nowp) % mod, mod) % mod;
    cout << aans << '\n';
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