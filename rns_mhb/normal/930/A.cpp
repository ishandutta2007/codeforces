#include<bits/stdc++.h>
using namespace std;

#define N 100010

int p[N], d[N], sum[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        cin >> p[i];
        d[i] = d[p[i]] + 1;
    }
    for(int i = 1; i <= n; i ++) sum[d[i]] ^= 1;
    int ans = 0;
    for(int i = 0; i < N; i ++) ans += sum[i];
    cout << ans << endl;
}