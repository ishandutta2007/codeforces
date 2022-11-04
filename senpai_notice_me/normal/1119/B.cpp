#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 5;

int n, h, a[MAXN];

int b[MAXN];

bool check(int k) {
    for (int i = 1; i <= k; ++i) {
        b[i] = a[i];
    }
    sort(b + 1, b + k + 1, greater<int>());
    int tot = 0;
    for (int i = 1; i <= k; i += 2) tot += b[i];
    return tot <= h;
}

int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        if (!check(k)) break;
        ans = k;
    }
    
    cout << ans << endl;
    
    return 0;
}