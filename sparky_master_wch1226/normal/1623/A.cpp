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
    int n, m, rx, ry, dx, dy;
    cin >> n >> m >> rx >> ry >> dx >> dy;
    int cnt = 0;
    int x = 1, y = 1;
    while(rx != dx && ry != dy) {
        cnt++;
        if(rx == 1 && x == -1) x = 1;
        if(rx == n && x == 1) x = -1;
        if(ry == 1 && y == -1) y = 1;
        if(ry == m && y == 1) y = -1;
        rx += x;
        ry += y;
    }
    cout << cnt << '\n';
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