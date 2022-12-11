#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, x, ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> x;
    for (ll i = 1; i * i <= x; i++) {
    	if (x % i == 0) {
    		if (x % i <= n && x / i <= n) {
    			if (i * i == x)
    				ans++;
    			else
    				ans += 2;
    		}
    	}
    }
    cout << ans;
}