// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

using P = pair<int, int>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ans = 0;
    long long cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long c = (d + p[i]) / p[i];
        cnt += c - 1;
        if (cnt <= i) {
            ans = max(ans, n - i);
        }
    }
    cout << ans << '\n';
    return 0;
}