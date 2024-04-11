#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

void solve() {
    int n;
    cin >> n;

    int l = 0, r = n + 3;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int x = m / 3;
        int y = m / 3 + (m % 3 >= 2);
        int z = m / 3 + (m % 3 >= 1);

        if((x * 1ll * y + y * 1ll * z + x * 1ll * z) * 2 >= n)
            r = m;
        else
            l = m;
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}