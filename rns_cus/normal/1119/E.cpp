#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    long long k = 0, rlt = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] >= 2 * k) {
            rlt += k + (a[i] - 2 * k) / 3;
            k = (a[i] - 2 * k) % 3;
        }
        else {
            rlt += a[i] / 2;
            k = k + a[i] - 3 * (a[i] / 2);
        }
    }
    cout << rlt << endl;
}