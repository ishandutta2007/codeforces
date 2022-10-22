#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

void solve() {
    int n;
    cin >> n;

    int a = 6, b = 10, c = 14;

    if(a + b + c >= n) {
        cout << "NO" << endl;
    } else {
        int d= n - a - b - c;

        if(d == a || d == b || d == c) {
            c = 15;
            d = n - a - b - c;
        }

        cout << "YES" << endl << a << ' '<< b << ' ' << c << ' ' << d << endl;
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}