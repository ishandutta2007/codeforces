#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(a) (a).begin(), (a).end()
#define int long long
using namespace std;
int mod = 998244353;
int powik(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2)
            res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}
int inv(int a) {
    return powik(a, mod - 2);
}
vector<int> fac;
int cnk(int n, int k) {
    return fac[n] * inv(fac[k]) % mod * inv(fac[n-k]) % mod;
}
signed main() {
    fac.assign(3e5 + 5, 1);
    for (int i = 1; i < fac.size(); ++i) {
        fac[i] = i * fac[i-1];
        fac[i] %= mod;
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int bl = 0, wh = 0, fwp = 0, swp = 0;
    cin >> n;
    int mayb = 1;
    int bw = 0, wb = 0, wpwp = 0;
    for (int i = 0; i < n; ++i) {
        string st;
        cin >> st;
        if (st[0] == st[1] and st[0] != '?')
            mayb = 0;
        if (st[0] == 'B' or st[1] == 'W')
            bw++;
        else if (st[0] == 'W' or st[1] == 'B')
            wb++;
        else
            wpwp++;
        if (st[0] == 'B')
            bl++;
        else if (st[0] == 'W')
            wh++;
        else
            fwp++;
        if (st[1] == 'B')
            wh--;
        else if (st[1] == 'W')
            bl--;
        else
            swp++;
    }
    int res = 0;
    for (int fbl = 0; fbl <= fwp; ++fbl) {
        int bl2 = bl + fbl, wh2 = wh + (fwp - fbl);
        if (bl2 + wh2 != swp)
            exit(1);
        if (bl2 >= 0 and wh2 >= 0) {
            res += cnk(fwp, fbl) * cnk(swp, bl2);
            res %= mod;
        }
    }
    if (mayb) {
        for (int i = 0; i <= wpwp; ++i) {
            if (i + bw != 0 and wpwp - i + wb != 0)
                res -= cnk(wpwp, i);
        }
        res %= mod;
        res += mod;
        res %= mod;
    }
    cout << res;
}