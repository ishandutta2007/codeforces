#include<bits/stdc++.h>
using namespace std;

#define N 5010

int a[N], ans[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) ans[i][i] = a[i];
    for(int i = n; i; i --) for(int j = i+1; j <= n; j ++) ans[i][j] = ans[i][j-1] ^ ans[i+1][j];
    for(int i = n; i; i --) for(int j = i+1; j <= n; j ++) ans[i][j] = max(ans[i][j], max(ans[i][j-1], ans[i+1][j]));
    int q, l, r;
    cin >> q;
    while(q --) {
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }
}