#include <bits/stdc++.h>
using namespace std;
int n, k, cur = 0, sum = 0;
int a[501][501];
int main() {
    cin >> n >> k;
    k--;
    for (int j = 0; j < k; j++)
        for (int i = 0; i < n; i++)
            a[i][j] = ++cur;
    for (int i = 0; i < n; i++)
        for (int j = k; j < n; j++) {
            a[i][j] = ++cur;
            if (j == k)
                sum += a[i][j];
        }
    cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}