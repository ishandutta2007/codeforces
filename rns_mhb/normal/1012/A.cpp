#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(2*n);
    for(int i = 0; i < 2*n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 1ll * (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
    for(int i = 0, j = n-1; j < 2*n; i ++, j ++) {
        long long cur = 1ll * (a[2*n-1] - a[0]) * (a[j] - a[i]);
        if(cur < ans) ans = cur;
    }
    cout << ans << endl;
}