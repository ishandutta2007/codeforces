#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 3, M = 6050, TN = (int)2e5 + 50;

int n, m;
int a[TN], w[TN];
ll p[2][M], dis[2][M][N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll res = 1, pw = x;
    while(k > 0) {
        if(k & 1) res *= pw, res %= mod;
        pw *= pw; pw %= mod;
        k /= 2;
    }
    return res;
}

ll ginv(ll x) {
    return fp(x, mod - 2);
}

void madd(ll &to, ll x) {
    to += x;
    to %= mod;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int tn = n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    int s[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        cin >> w[i], sum += w[i];
        s[a[i]] += w[i];
    }

    int nw = 1, la = 0;
    p[nw][1 + M / 2] = 1;
    n = 2;
    for(int i = 0; i < n; i++) {
        s[i] %= mod;
        dis[nw][1 + M / 2][i] = s[i];
    }
    for(int k = 0; k < m; k++) {
        swap(nw, la);
        memset(dis[nw], 0, sizeof(dis[nw]));
        memset(p[nw], 0, sizeof(p[nw]));
        for(int rsum = sum - M / 2, csum = 1; csum < M - 1; rsum++, csum++) {
//            if((rsum - sum) % 2 != k % 2) continue;

            ll add = dis[la][csum][1];
            ll del = dis[la][csum][0];
            if(add == 0 && del == 0) continue;
            add %= mod;
            del %= mod;
            ll denom = ginv((add + del) % mod);
            ll p_add = add * denom % mod;
            ll p_del = del * denom % mod;
            madd(p[nw][csum + 1], p_add * p[la][csum]);
            madd(p[nw][csum - 1], p_del * p[la][csum]);
            for(int j = 0; j < n; j++) {
                if(j) {
                    madd(dis[nw][csum+1][j], p_add * (dis[la][csum][j] + p[la][csum]));
                    madd(dis[nw][csum-1][j], p_del * dis[la][csum][j]);
                }
                else {
                    madd(dis[nw][csum-1][j], p_del * (dis[la][csum][j] - p[la][csum]));
                    madd(dis[nw][csum+1][j], p_add * dis[la][csum][j]);
                }
            }
        }
    }
    ll exp[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < M; j++) exp[i] += dis[nw][j][i];
        exp[i] %= mod;
    }
//    cout << exp[0] << " " << exp[1] << endl;
    for(int i = 0; i < tn; i++) {
        ll res = exp[a[i]] * w[i] % mod * ginv(s[a[i]]);
        cout << (res % mod + mod) % mod << "\n";
    }

}