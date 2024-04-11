#include<bits/stdc++.h>
using namespace std;

#define N 2010

int a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(a[i] == 1) cnt ++;
    if(cnt) {
        cout << n - cnt << endl;
        return 0;
    }
    int ans = N;
    for(int i = 1; i <= n; i ++) {
        int g = a[i];
        for(int j = i; j <= n; j ++) {
            g = __gcd(g, a[j]);
            if(g == 1) {
                ans = min(ans, j-i);
                break;
            }
        }
    }
    if(ans == N) ans = -1;
    else ans += n-1;
    cout << ans << endl;
}