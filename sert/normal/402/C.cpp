#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

int t, n, p;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> t;
    while (t --> 0) {
        cin >> n >> p;
        p += n * 2;
        for (int len = 1; p; len++)
            for (int v = 0; v < n && p > 0; v++) {
                cout << v + 1 << " " << (v + len) % n + 1 << "\n";
                p--;
            }
    }

    //return 0;
}