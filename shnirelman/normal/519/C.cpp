//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 100;
const int K = 400;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;

    while(n > 0 && m > 0 && n + m >= 3) {
        if(n < m)
            swap(n, m);

        n -= 2;
        m--;

        ans++;
    }

    cout << ans << endl;
}