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
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
        }
        int c = sum - n;
        if (c % 2 == 0) {
            cout << "maomao90\n";
        }
        else {
            cout << "errorgorn\n";
        }
    }

    return 0;
}