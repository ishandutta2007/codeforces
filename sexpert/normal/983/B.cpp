#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int f[MAXN][MAXN], ma[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i][i];
        ma[i][i] = f[i][i];
    }
    for(int d = 1; d < n; d++) {
        for(int l = 1; l + d <= n; l++) {
            f[l][l + d] = f[l][l + d - 1] ^ f[l + 1][l + d];
            ma[l][l + d] = f[l][l + d];
            ma[l][l + d] = max(ma[l][l + d], ma[l][l + d - 1]);
            ma[l][l + d] = max(ma[l][l + d], ma[l + 1][l + d]);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << ma[l][r] << '\n';
    }
}