#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    if (a[0] != a[n-1]) cout << n - 1 << endl;
    else {
        int i, j;
        for (i = 1; i < n && a[i] == a[i-1]; i ++);
        for (j = n - 1; j > 0 && a[j] == a[j-1]; j --);
        cout << max(j - 1, n - i - 1) << endl;
    }

    return 0;
}