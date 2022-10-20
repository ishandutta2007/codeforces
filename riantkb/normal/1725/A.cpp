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
    long long h, w;
    cin >> h >> w;
    if (w == 1) {
        cout << h - 1 << '\n';
    }
    else {
        cout << (w - 1) * h << '\n';

    }
    return 0;
}