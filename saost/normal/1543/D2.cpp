#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, k;

int xor_add(int x, int y) {
    int z = 0, p = 1;
    while (x > 0 || y > 0) {
        int w = x%k + y%k;
        if (w >= k) w -= k;
        z += w * p;
        p *= k;
        x /= k;
        y /= k;
    }
    return z;
}

int xor_minus(int x, int y) {
    int z = 0, p = 1;
    while (x > 0 || y > 0) {
        int w = x%k - y%k;
        if (w < 0) w += k;
        z += w * p;
        p *= k;
        x /= k;
        y /= k;
    }
    return z;
}

int main()
{
    ///ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int w = 0, ans, res = 3;
        for(int i=0; i<n; ++i) {
            if (i == 0) w = 0; else w = xor_minus(i, i-1);
            cout << w << '\n';
            fflush(stdout);
            cin >> ans;
            if (ans) break;
            ++i;
            w = xor_minus(i-1, i);
            cout << w << '\n';
            fflush(stdout);
            cin >> ans;
            if (ans) break;
        }
        fflush(stdout);
    }
}