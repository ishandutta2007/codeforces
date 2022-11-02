#include<bits/stdc++.h>
using namespace std;

#define N 400010

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n + m; i ++) f[i] = i;
    for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        y += n;
        x = find(x), y = find(y);
        if(x == y) continue;
        f[x] = y;
    }
    int ans = -1;
    for(int i = 1; i <= n + m; i ++) if(find(i) == i) ans ++;
    cout << ans << endl;
}