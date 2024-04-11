#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll t, k, a[N], l, r;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> t >> k;

    a[0] = 1;
    for (int i = 1; i < N; i++) {
        a[i] = (a[i - 1] + (i >= k ? a[i - k] : 0)) % md;
    }
    a[0] = 0;
    for (int i = 1; i < N; i++)
        a[i] += a[i - 1];

    while (t--) {
        cin >> l >> r;
        cout << (a[r] - a[l - 1] + md) % md << "\n";
    }

    //return 0;
}