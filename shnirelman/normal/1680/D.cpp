#include <bits/stdc++.h>

using namespace std;
using li = long long;

const int N = 3013;

int a[N];

li mn[N], mx[N];

/*
li mn2 = 0, mx2 = 0;
        for(int j = 0; i + j <= n; j++) {
            if(mn1 + mn2 + mn[i + j] <= 0 && mx1 + mx2 + mx[i + j] >= 0) {

            }
*/

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mn[n] = mx[n] = 0;

    for(int i = n - 1; i >= 0; i--) {
        mn[i] = mn[i + 1] + (a[i] == 0 ? -k : a[i]);
        mx[i] = mx[i + 1] + (a[i] == 0 ? k : a[i]);
    }

    li ans = -2;
    li mn1 = 0, mx1 = 0;
    for(int i = 0; i <= n; i++) {
        if(mn1 + mn[i] <= 0 && mx1 + mx[i] >= 0) {
            if(mn1 <= 0)
                ans = max(ans, min(-mn1, mx[i]));
            if(mx1 >= 0)
                ans = max(ans, min(mx1, -mn[i]));
        }

        li mn2 = 0, mx2 = 0;
        for(int j = 0; i + j <= n; j++) {
            if(mn1 + mn2 + mn[i + j] <= 0 && mx1 + mx2 + mx[i + j] >= 0) {
                if(mn1 <= 0 && mx2 >= 0) {
                    ans = max(ans, min(-mn[i + j] - mn1, mx2));
                }

                if(mn2 <= 0 && mx1 >= 0) {
                    ans = max(ans, min(mx[i + j] + mx1, -mn2));
                }
            }

            if(i + j < n) {
                mn2 += (a[i + j] == 0 ? -k : a[i + j]);
                mx2 += (a[i + j] == 0 ? k : a[i + j]);
            }
        }

        if(i < n) {
            mn1 += (a[i] == 0 ? -k : a[i]);
            mx1 += (a[i] == 0 ? k : a[i]);
        }

    }

    cout << ans + 1 << endl;
}