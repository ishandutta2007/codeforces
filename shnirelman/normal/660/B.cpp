#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1000 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(4, -1));
    for(int i = 0; i < min(n * 2, m); i++) {
        if(i % 2 == 0)
            a[i / 2][0] = i;
        else
            a[i / 2][3] = i;
    }

    for(int i = n * 2; i < m; i++) {
        if(i % 2 == 0)
            a[(i - 2 * n) / 2][1] = i;
        else
            a[(i - 2 * n) / 2][2] = i;
    }

    for(int i = 0; i < n; i++) {
        if(a[i][1] != -1)
            cout << a[i][1] + 1 << ' ';
        if(a[i][0] != -1)
            cout << a[i][0] + 1 << ' ';
        if(a[i][2] != -1)
            cout << a[i][2] + 1 << ' ';
        if(a[i][3] != -1)
            cout << a[i][3] + 1 << ' ';
    }
}