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

int n, m, d;
int bel[N];
int freq[N], cnt[N];
int in[N];

struct FWT {
    // Please set N!!!
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> d;
    fwt.N = (1 << m);
    for(int i = 0; i < m; i++) {
        int len;
        cin >> len;
        while(len--) {
            int a; cin >> a; a--; bel[a] = i;
        }
    }
    for(int i = 0; i < fwt.N; i++) cnt[i] = cnt[i>>1] + (i & 1);
    for(int i = 0; i < d - 1; i++) in[bel[i]]++;
    for(int i = d - 1; i < n; i++) {
        in[bel[i]]++;
        int msk = 0;
        for(int j = 0; j < m; j++) if(in[j]) msk |= (1 << j);
        freq[msk]++;
        in[bel[i - (d - 1)]]--;
    }
    fwt.FWTor(freq, 1);
    int mx = 0;
    for(int i = 0; i < fwt.N; i++) {
        if(freq[i] == 0) mx = max(mx, cnt[i]);
    }
    cout << m - mx << endl;
}