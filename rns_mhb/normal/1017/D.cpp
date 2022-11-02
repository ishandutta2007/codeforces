#include<bits/stdc++.h>
using namespace std;

int ans[1<<12][111], cnt[1<<12], val[1<<12];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> w(n);
    for(int i = 0; i < n; i ++) cin >> w[i];
    for(int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        int x = 0;
        for(int j = 0; j < n; j ++) if(s[j] == '1') x ^= 1<<j;
        cnt[x] ++;
    }
    val[0] = 0;
    for(int i = 1; i < (1<<n); i ++) val[i] = val[i&(i-1)] + w[__builtin_ctz(i)];
    for(int i = 0; i < (1<<n); i ++) if(cnt[i]) {
        for(int j = 0; j < (1<<n); j ++) {
            int k = val[i^j^((1<<n)-1)];
            if(k <= 100) ans[j][k] += cnt[i];
        }
    }
    for(int i = 0; i < (1<<n); i ++) for(int j = 1; j <= 100; j ++) ans[i][j] += ans[i][j-1];
    while(q --) {
        int k;
        string s;
        cin >> s >> k;
        int x = 0;
        for(int j = 0; j < n; j ++) if(s[j] == '1') x ^= 1<<j;
        cout << ans[x][k] << endl;
    }
}