#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<long long> v1(100010), v2(100010);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1) {
                for (int j = 1; j * j <= a[i + 1]; ++j) {
                    {
                        int x = j;
                        int y = (a[i] + x - 1) / x;
                        ans = (ans + v1[x] * (y - 1) % M * (i + 1)) % M;
                        v2[a[i] / y] = (v2[a[i] / y] + v1[x]) % M;
                        v1[x] = 0;
                    }
                    {
                        int x = a[i + 1] / j;
                        int y = (a[i] + x - 1) / x;
                        ans = (ans + v1[x] * (y - 1) % M * (i + 1)) % M;
                        v2[a[i] / y] = (v2[a[i] / y] + v1[x]) % M;
                        v1[x] = 0;
                    }
                }
            }
            {
                int x = a[i];
                v1[x] = 1;
                int y = (a[i] + x - 1) / x;
                ans = (ans + v1[x] * (y - 1) % M * (i + 1)) % M;
                v2[a[i] / y] = (v2[a[i] / y] + v1[x]) % M;
                v1[x] = 0;
            }
            swap(v1, v2);
        }
        for (int j = 1; j * j <= a[0]; ++j) {
            {
                int x = j;
                v1[x] = 0;
            }
            {
                int x = a[0] / j;
                v1[x] = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}