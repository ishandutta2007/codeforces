#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a < c) {
        cout << 1 << ' ';
    } else {
        cout << -1 << ' ';
    }

    cout << (a * 1ll * b > c ? b : -1) << endl;
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}