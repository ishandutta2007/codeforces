#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + (int)1e5, mod = (int)1e9 + 7, inv2 = (int)5e8 + 4, M = (int)1e5 + 50, INF = (int)1e9;

int add(int a, int b) {
    a = (a + b) % mod;
    if(a < 0) a += mod;
    return a;
}

int mul(int a, int b) {
    return (int)(1LL * a * b % mod);
}

int p[N];

int n, m;
string str[20];
int freq[N], cnt[N], res[N];

struct FWT {
    int N;
    void FWTor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k + mid] = add(a[j + k], a[j + k + mid]);
                    else a[j + k + mid] = add(a[j + k + mid], -a[j + k]);
    }
    void FWTand(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++)
                    if(opt == 1) a[j + k] = add(a[j + k], a[j + k + mid]);
                    else a[j + k] = add(a[j + k], -a[j + k + mid]);
    }
    void FWTxor(int *a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1)
            for(int R = mid << 1, j = 0; j < N; j += R)
                for(int k = 0; k < mid; k++) {
                    int x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = add(x, y), a[j + k + mid] = add(x, -y);
                    else a[j + k] = mul(add(x, y), inv2), a[j + k + mid] = mul(add(x, -y), inv2);
                }

    }
} fwt;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> str[i];
    fwt.N = (1 << n);
    for(int i = 0; i < (1 << n); i++) {
        int c = __builtin_popcount(i);
        cnt[i] = min(c, n - c);
    }
    for(int j = 0; j < m; j++) {
        int x = 0;
        for(int i = 0; i < n; i++) x *= 2, x += str[i][j] - '0';
        freq[x]++;
    }
    fwt.FWTxor(freq, 1);
    fwt.FWTxor(cnt, 1);
    int fres = INF;
    for(int i = 0; i < fwt.N; i++) res[i] = mul(freq[i], cnt[i]);
    fwt.FWTxor(res, -1);
    for(int i = 0; i < fwt.N; i++) fres = min(fres, res[i]);
    cout << fres << endl;



}