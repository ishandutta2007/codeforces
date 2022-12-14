#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int d = max(max(n * 2, m * 3), 3 * (n + m) / 2);
    while (d / 2 + d / 3 - d / 6 < n + m || d / 2 < n || d / 3 < m) {
        ++d;
    }
    cout << d << '\n';
    return 0;
}