#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e3 + 5;
const int INF = 1e9;
int fdp[MAXN][100][100], sdp[MAXN][100][100], a[MAXN], pf[MAXN], n;

int fcalc(int l, int k, int d);
int scalc(int l, int k, int d);

int fcalc(int l, int k, int d) {
    if(fdp[l][k][d] != INF)
        return fdp[l][k][d];
    int r = l + d;
    fdp[l][k][d] = -INF;
    if(l + r + k > n)
        return fdp[l][k][d] = 0;
    fdp[l][k][d] = pf[l + k] - pf[l] + scalc(l + k, k, d);
    if(l + r + k + 1 <= n)
        fdp[l][k][d] = max(fdp[l][k][d], pf[l + k + 1] - pf[l] + scalc(l + k + 1, k + 1, d));
    return fdp[l][k][d];
}

int scalc(int l, int k, int d) {
    if(sdp[l][k][d] != INF)
        return sdp[l][k][d];
    int r = l - k + d;
    sdp[l][k][d] = INF - 1;
    if(l + r + k > n)
        return sdp[l][k][d] = 0;
    sdp[l][k][d] = -(pf[n - r] - pf[n - r - k]) + fcalc(l, k, d);
    if(l + r + k + 1 <= n)
        sdp[l][k][d] = min(sdp[l][k][d], -(pf[n - r] - pf[n - r - k - 1]) + fcalc(l, k + 1, d + 1));
    return sdp[l][k][d];
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < 100; j++)
            for(int k = 0; k < 100; k++)
                fdp[i][j][k] = sdp[i][j][k] = INF;
    cout << fcalc(0, 1, 0) << '\n';
}