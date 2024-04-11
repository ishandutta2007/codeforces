// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
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
        int n, k;
        cin >> n >> k;
        int mask = n - 1;
        if (k < n - 1) {
            vector<int> a(n / 2), b(n / 2);
            for (int i = 0; i < n / 2; ++i) {
                a[i] = i;
                b[i] = mask ^ i;
            }
            for (int i = 0; i < n / 2; ++i) {
                if (a[i] == k) {
                    swap(b[0], b[i]);
                    break;
                }
                if (b[i] == k) {
                    swap(a[i], b[0]);
                    break;
                }
            }
            for (int i = 0; i < n / 2; ++i) {
                cout << a[i] << ' ' << b[i] << '\n';
            }
        }
        else {
            if (n == 4) {
                cout << -1 << '\n';
                continue;
            }
            vector<int> a(n / 2), b(n / 2);
            for (int i = 0; i < n / 2; ++i) {
                a[i] = i;
                b[i] = mask ^ i;
            }
            a[0] = 0;
            b[0] = mask ^ 2;
            a[1] = 1;
            b[1] = 3;
            a[2] = 2;
            b[2] = mask ^ 3;
            a[3] = mask;
            b[3] = mask ^ 1;
            for (int i = 0; i < n / 2; ++i) {
                cout << a[i] << ' ' << b[i] << '\n';
            }
        }
    }
    return 0;
}