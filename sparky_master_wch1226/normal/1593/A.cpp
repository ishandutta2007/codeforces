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
void solve(int TC) {
    int a, b, c;
    cin >> a >> b >> c;
    int win = max(a, max(b, c));
    int cnt = 0;
    bool aa = true, bb = true, cc = true;
    if(a == win) cnt++, aa = false;
    if(b == win) cnt++, bb = false;
    if(c == win) cnt++, cc = false;
    if(cnt >= 2) {
        aa = bb = cc = true;
    }
    cout << win - a + aa << ' ' << win - b + bb << ' ' << win - c + cc << '\n'; 
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