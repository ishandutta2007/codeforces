#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, h, a[N], b[N];

int main() {
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    int t;
    for (t = 1; t <= n; t ++) {
        for (int i = 0; i < t; i ++) b[i] = a[i];
        sort(b, b + t);
        long long rlt = 0;
        for (int i = t - 1; i >= 0; i -= 2) rlt += b[i];
        if (rlt > h) break;
    }
    cout << t - 1 << endl;
}