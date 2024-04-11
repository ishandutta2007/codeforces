#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;

int pow2(int n, li k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int main() {
    li n, m, k;
    cin >> n >> m >> k;

    if(k == -1 && n % 2 != m % 2) {
        cout << 0 << endl;
        return 0;
    }

    cout << pow2(pow2(2, n - 1), m - 1);
}