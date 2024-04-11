#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long m = 1;
        long long ma = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                m *= 2;
                a[i] /= 2;
            }
            sum += a[i];
            ma = max(ma, a[i]);
        }
        cout << sum - ma + ma * m << '\n';

    }
    return 0;
}