#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, u;
    cin >> n >> u;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    double ans = -1;
    for(int i = 1, j = 1; i <= n; i ++) {
        while(j <= n && a[j] - a[i] <= u) j ++;
        if(j-1 > i+1) ans = max(ans, 1.0 * (a[j-1]-a[i+1]) / (a[j-1]-a[i]));
    }
    if(ans > -0.5) {
        printf("%.10lf\n", ans);
        return 0;
    }
    cout << ans << endl;
}