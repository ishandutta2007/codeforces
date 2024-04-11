#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 52, M = 2560;
#define madd(x, y) x += y, x %= mod;
#define ginv(x) fp(x, mod - 2)

int n, m;
int a[N], w[N];
ll p[2][M], dis[2][M][N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

//void madd(ll &to, ll x) {
//    to += x;
//    to %= mod;
//}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> w[i], sum += w[i];

    int nw = 1, la = 0;
    p[nw][sum] = 1;
    for(int i = 0; i < n; i++) {
        dis[nw][sum][i] = w[i];
    }
    for(int k = 0; k < m; k++) {
        swap(nw, la);
        memset(dis[nw], 0, sizeof(dis[nw]));
        memset(p[nw], 0, sizeof(p[nw]));
        for(int csum = 1; csum < M - 1; csum++) {
            ll add = 0, del = 0;
            for(int j = 0; j < n; j++) {
                if(a[j]) add += dis[la][csum][j];
                else del += dis[la][csum][j];
            }
            add %= mod;
            del %= mod;
            ll denom = ginv((add + del) % mod);
            ll p_add = add * denom % mod;
            ll p_del = del * denom % mod;
            madd(p[nw][csum + 1], p_add * p[la][csum]);
            madd(p[nw][csum - 1], p_del * p[la][csum]);
            ll addinv = ginv(add);
            ll delinv = ginv(del);
            for(int j = 0; j < n; j++) {
                if(a[j]) {
                    madd(dis[nw][csum+1][j], p_add * (dis[la][csum][j] + p[la][csum] * dis[la][csum][j] % mod * addinv % mod));
                    madd(dis[nw][csum-1][j], p_del * dis[la][csum][j]);
                }
                else {
                    madd(dis[nw][csum-1][j], p_del * (dis[la][csum][j] + p[la][csum] * (-dis[la][csum][j]) % mod * delinv % mod));
                    madd(dis[nw][csum+1][j], p_add * dis[la][csum][j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        ll res = 0;
        for(int j = 1; j < M; j++) res += dis[nw][j][i];
        cout << (res % mod + mod) % mod << endl;
    }
}