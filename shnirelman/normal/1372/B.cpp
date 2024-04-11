#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/


void solve() {
    int n;
    cin >> n;

//    int mn = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
//            mn = i;
            cout << n / i << ' ' << n - n / i << endl;
            return;
        }

    }

    cout << 1 << ' ' << n - 1 << endl;
//    cout << mx << ' ' << n - mx << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}