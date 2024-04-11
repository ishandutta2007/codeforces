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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*
1
10 6
14 6
2 20
9 10
13 18
15 12
11 7

*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    vector<int> sum(1 << n, 0);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1)
                sum[mask] += a[i];
    }

    for(int mask = 0; mask < (1 << n); mask++) {
        int msk = (1 << n) - 1 - mask;
        for(int ms = msk; ms > 0; ms = (ms - 1) & msk) {
            if(sum[mask] == sum[ms]) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" <<  endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}