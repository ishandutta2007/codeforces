#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
const int MOD = 1e9 + 7;

int power(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    int x = power(n, k / 2);
    int ans = x * x % MOD;
    if (k % 2 == 0) {
        return ans;
    } else {
        return (ans * n) % MOD;
    }
}

int main() {
    cout.precision(20);
    long long n, n1, n2;
    cin >> n >> n1 >> n2;
    vector <long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    if (n1 > n2) swap(n1, n2);
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n1; i++) {
        sum1 += a[i];
    }
    for (int i = n1; i < n2 + n1; i++) {
        sum2 += a[i];
    }
    cout << (double) (sum1 * n2 + sum2 * n1) / (n1 * n2);
}