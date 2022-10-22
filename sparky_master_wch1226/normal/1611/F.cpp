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
int sps[200005][25];
int rmq(int l, int r) {
    int range = r - l + 1;
    int aa = -1;
    while(range) {
        range >>= 1;
        aa++;
    }
    //cerr << l << ' ' << r << ' ' << min(sps[l][aa], sps[r - (1 << aa) + 1][aa]) << '\n';
    return min(sps[l][aa], sps[r - (1 << aa) + 1][aa]);
}
void solve(int TC) {
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> sps[i][0];
        sps[i][0] += sps[i - 1][0];
    }
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j <= n; j++) {
            sps[j][i] = min(sps[j][i - 1], sps[min(n, j + (1 << (i - 1)))][i - 1]);
            //cerr << sps[i][j] << ' ';
        }
        //cerr << '\n';
    }
    int ans = -1;
    int al, ar;
    for(int i = 1; i <= n; i++) {
        int l = i - 1, r = n;
        while(l < r) {
            int m = (l + r + 1) / 2;
            if(rmq(i - 1, m) < sps[i - 1][0] - s) r = m - 1;
            else l = m;
        }
        if(l - i + 1 > ans) {
            ans = l - i + 1;
            al = i;
            ar = l;
        } 
        //ans = max(ans, l - i + 1);
    }
    //if(ans == 0) ans--;
    //cout << ans << '\n';
    if(ans == 0) cout << "-1\n";
    else cout << al << ' ' << ar << '\n';
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