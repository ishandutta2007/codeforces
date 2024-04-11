#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

void solve() {
    int n, k1, k2, a, b;
    cin >> n >> k1 >> k2 >> a >> b;

    if(k1 < k2)
        swap(k1, k2);

    int a1 = k2 + (k1 - k2) / 2;
    int b1 = (n - k1) + (k1 - k2) / 2;

    cout << (a <= a1 && b <= b1 ? "Yes" : "No") << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}