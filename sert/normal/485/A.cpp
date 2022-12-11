#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll x, m, u[N];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> x >> m;
    while (!u[x]) {
        if (x == 0) {
            cout << "Yes\n";
            return 0;
        }
        u[x] = true;
        x = (x + x) % m;
    }
    cout << "No\n";
    return 0;
}