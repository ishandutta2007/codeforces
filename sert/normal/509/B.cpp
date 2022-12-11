#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, a[N], mn = N, mx = -N, k;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	mn = min(mn, a[i]);
    	mx = max(mx, a[i]);
    }

    if (mx - mn > k) {
    	cout << "NO";
    	return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < mn; j++)
    		cout << "1 ";
    	for (int j = 0; j < a[i] - mn; j++)
    		cout << 1 + j << " ";
    	cout << "\n";
    }

    return 0;
}