#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int jmp[MAXN][LOG];
int chain[MAXN];
int minr[MAXN], perm[MAXN], pre[MAXN], arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        cin >> perm[i];
    for(int i = 1; i <= n; i++) {
        if(i < n) chain[perm[i]] = perm[i + 1];
        else chain[perm[n]] = perm[1];
    }
    for(int i = 1; i < MAXN; i++)
        pre[i] = m + 1;
    jmp[m + 1][0] = m + 1;
    for(int i = 1; i <= m; i++)
        cin >> arr[i];
    for(int i = m; i >= 1; i--) {
        jmp[i][0] = pre[chain[arr[i]]];
        pre[arr[i]] = i;
    }
    for(int l = 1; l < LOG; l++)
        for(int i = m + 1; i >= 1; i--)
            jmp[i][l] = jmp[jmp[i][l - 1]][l - 1];
    for(int i = 1; i <= m; i++) {
        int po = i;
        for(int l = LOG - 1; l >= 0; l--)
            if((n - 1) & (1<<l))
                po = jmp[po][l];
        minr[i] = po;
        //cout << minr[i] << endl;
    }
    for(int i = m - 1; i >= 1; i--)
        minr[i] = min(minr[i], minr[i + 1]);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << (r >= minr[l] ? '1' : '0');
    }
    cout << '\n';
}