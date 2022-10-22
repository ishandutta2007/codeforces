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
    int n, k;
    cin >> n >> k;

    if(k == 3) {
        if(n % 4 == 0)
            cout << n / 2 << ' ' << n / 4 << ' '<< n / 4 << endl;
        else if(n % 4 == 1)
            cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
        else if(n % 4 == 2)
            cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << endl;
        else
            cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}