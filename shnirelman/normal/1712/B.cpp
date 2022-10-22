#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);


void solve() {
    int n;
    cin >> n;

    if(n % 2 == 1) {
        cout << 1 << ' ';
        for(int i = 2; i < n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
    } else {
        for(int i = 1; i < n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}