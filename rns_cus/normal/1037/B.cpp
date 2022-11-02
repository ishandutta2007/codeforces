#include <bits/stdc++.h>
using namespace std;

#define N 200020

int n, s, a[N];

int main() {
    scanf("%d %d", &n, &s);
    int m = n / 2;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    long long rlt = 0;
    for (int i = 0; i < n; i ++) {
        if (i < m && a[i] > s) rlt += a[i] - s;
        if (i == m) rlt += abs(a[i] - s);
        if (i > m && a[i] < s) rlt += s - a[i];
    }
    cout << rlt << endl;
}