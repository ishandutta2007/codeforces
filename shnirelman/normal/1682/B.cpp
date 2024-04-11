#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int x = 1;
    while(x < n)
        x *= 2;
    x--;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != i)
            x &= i;
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}