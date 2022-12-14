#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 2e7 + 34;

bool u[N];
ll pr, rub;
int qq[100], len;

bool is_rub(int x) {
	len = 0;
	while (x > 0) {
		qq[len++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < len / 2; i++)
		if (qq[i] != qq[len - i - 1])
			return false;
	return true;
}
int p, q;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> p >> q;
    for (ll i = 2; i < N; i++)
    	if (!u[i])
    		for (ll j = i * i; j < N; j += i)
    			u[j] = true;
    u[0] = u[1] = true;
    ll ans = -1;
    for (ll i = 1; i < N; i++) {
    	pr += int(!u[i]);
    	rub += int(is_rub(i));
    	if (pr * q <= p * rub)
    		ans = i;
    }
    cout << ans << "\n";
    //cout << clock();
}