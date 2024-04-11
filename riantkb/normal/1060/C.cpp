#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const long long LM = (long long)2e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    long long x;
    cin >> x;
    vector<long long> mina(n + 1, LM), minb(m + 1, LM);
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            mina[j - i + 1] = min(mina[j - i + 1], sum);
        }
    }
    for (int i = 0; i < m; ++i) {
        long long sum = 0;
        for (int j = i; j < m; ++j) {
            sum += b[j];
            minb[j - i + 1] = min(minb[j - i + 1], sum);
        }
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (mina[i] * minb[j] <= x) {
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}