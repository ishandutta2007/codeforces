#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;

void solve() {
    int a, b;
    cin >> a >> b;

    if(b == 1) {
        cout << "NO" << endl;
    } else {
        if(b > 2)
            cout << "YES" << endl << a << ' ' << a * 1ll * (b - 1) << ' ' << a * 1ll * b << endl;
        else if(b == 2)
            cout << "YES" << endl << a * 3 << ' ' << a * 5 << ' ' << a * 8 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();



}