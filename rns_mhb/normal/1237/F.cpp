#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int N = max(h, w) + 10;
    vector <int> fac(N), rfac(N);
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    rfac[0] = rfac[1] = 1;
    for(int i = 2; i < N; i ++){
        int t = mod / i;
        rfac[i] = (1ll * t * (mod - rfac[mod % i])) % mod;
    }
    for(int i = 1; i < N; i ++) rfac[i] = 1ll * rfac[i-1] * rfac[i] % mod;
    auto P = [&] (int n, int m) {return 1ll * fac[n] * rfac[n-m] % mod;};
    vector <bool> br(h, true), bc(w, true);
    n <<= 1;
    while(n --) {
        int x, y;
        cin >> x >> y;
        br[x-1] = false;
        bc[y-1] = false;
    }
    int gr = 0, gc = 0;
    for(int i = 0; i < h; i ++) gr += br[i];
    for(int i = 0; i < w; i ++) gc += bc[i];
    int hr = gr>>1, hc = gc>>1;
    vector<vector<int> > dr(h+1, vector<int> (hr+1));
    vector<vector<int> > dc(w+1, vector<int> (hc+1));
    dr[0][0] = dc[0][0] = 1;
    for(int i = 1; i <= h; i ++) for(int j = 0; j <= hr; j ++) {
        dr[i][j] = dr[i-1][j];
        if(j && i > 1 && br[i-1] && br[i-2]) (dr[i][j] += dr[i-2][j-1]) %= mod;
    }
    for(int i = 1; i <= w; i ++) for(int j = 0; j <= hc; j ++) {
        dc[i][j] = dc[i-1][j];
        if(j && i > 1 && bc[i-1] && bc[i-2]) (dc[i][j] += dc[i-2][j-1]) %= mod;
    }
    int ans = 0;
    for(int i = 0; i <= hr; i ++) for(int j = 0; j <= hc; j ++) {
        if(gr-2*i < j || gc-2*j < i) continue;
        ans = (ans + 1ll * P(gr-2*i, j) * P(gc-2*j, i) % mod * dr[h][i] % mod * dc[w][j]) % mod;
    }
    cout << ans << endl;
}