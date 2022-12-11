#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, sum, cs, ans;
ll pr[N], sf[N], a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	sum += a[i];
    }

    if (sum % 3) {
    	cout << 0;
    	return 0;
    }
    sum /= 3;

    for (int i = n - 1; i >= 0; i--)
    	sf[i] = sf[i + 1] + a[i];
    for (int i = n - 1; i >= 0; i--)
    	sf[i] = sf[i + 1] + int(sf[i] == sum);

    for (int i = 0; i < n - 2; i++) {
    	cs += a[i];
    	if (cs == sum)
    		ans += sf[i + 2];
    }

    cout << ans;

    return 0;
}