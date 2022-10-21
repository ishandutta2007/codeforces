/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description:
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)530000;
const ll mod = 998244353;
const int g = 3;

int rev[N], w[2][N];

int fp(int x, int k){
    int c = 1;
    for(; k; k >>= 1, x = int(x * 1LL * x % mod)) if(k & 1) c = int(c * 1LL * x % mod);
    return c;
}

void init(int len){
    for(int i = 0; i < len; i++){
        int y = 0, x = i;
        for(int k = 1; k < len; k *= 2, x >>= 1) (y <<= 1) |= (x & 1);
        rev[i] = y;
    }
    w[0][0] = w[1][0] = 1;
    int mp = fp(g, (mod-1)/len), ni = fp(mp, mod - 2);
    for(int i = 1; i < len; i++){
        w[0][i] = int(w[0][i-1] * 1LL * mp % mod);
        w[1][i] = int(w[1][i-1] * 1LL * ni % mod);
    }
}

void NTT(vector<int> &y, int on, int len){
    y.resize(len, 0);
    for(int i = 0; i < len; i++) if(i > rev[i]){int tmp = y[i]; y[i] = y[rev[i]], y[rev[i]] = tmp;}
    for(int h = 2; h <= len; h <<= 1) {
        int wi = len / h;
        for (int j = 0; j < len; j += h) {
            int l = 0;
            for (int k = j; k < j + h / 2; k++) {
                int u = y[k];
                int t = int(1LL * w[on==-1][l] * y[k + h / 2] % mod);
                y[k] = (u + t) % mod;
                y[k + h / 2] = ((u - t) % mod + mod) % mod;
                l += wi;
            }
        }
    }

    if(on == -1){
        int ni = fp(len, mod-2);
        for(int i = 0; i < len; i++) y[i] = int(1LL * y[i] * ni % mod);
    }
}


int n;
int k;
int h[N];

int solve(int cnt) {
    if(cnt == 0) return 0;
    int len = 1;
    while(len < 2 * cnt + 1) len *= 2;
    init(len);
    vector<int> y = {1, (k - 2), 1};
    NTT(y, 1, len);
    for(int i = 0; i < len; i++) y[i] = fp(y[i], cnt);
    NTT(y, -1, len);
    int res = 0;
    for(int i = cnt + 1; i < y.size(); i++) res = (int)((res + y[i]) % mod);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int cnt_same = 0, cnt_diff = 0;

    for(int i = 1; i <= n; i++) {
        int cur = h[i], nxt = h[i % n + 1];
        if(cur == nxt) cnt_same++;
        else cnt_diff++;
    }
//    cout << solve(cnt_diff) << endl;
    ll res = 1LL * solve(cnt_diff) * fp(k, cnt_same) % mod;
    cout << (res % mod + mod) % mod << endl;


}