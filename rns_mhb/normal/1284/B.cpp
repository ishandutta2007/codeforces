#include<bits/stdc++.h>
using namespace std;

int b[1000010], c[1000010], a[1000010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        for(int j = 1; j <= m; j ++) cin >> a[j];
        int flag = 0;
        for(int j = 2; j <= m; j ++) if(a[j-1] < a[j]) {
            flag = 1;
            break;
        }
        if(flag == 0) {
            b[a[1]] ++;
            c[a[m]] ++;
        }
    }
    long long ans = 1ll * n * n;
    for(int i = 1; i < 1000010; i ++) b[i] += b[i-1];
    for(int i = 0; i < 1000010; i ++) ans -= 1ll * c[i] * b[i];
    cout << ans << endl;
}