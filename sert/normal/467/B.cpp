#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int n, m, k, a[100000];

int cnt(int x) {
    //cerr << x << "\n";
    int ans = 0;
    while (x) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int main() {
    int ans = 0;
  //  freopen("a.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i <= m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        if (cnt(a[i] ^ a[m]) <= k)
            ans++;
    }
    cout << ans;
    return 0;
}