#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
int lastbit[MAXN];
ll ans, tot;
ll val[MAXN], mask[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val[i] >> mask[i];
		tot += val[i];
		for(ll k = 61; k >= 0; k--) {
			if(mask[i] & (1ll << k))
				lastbit[i] = k;
		}
	}
	if(tot < 0)
	    for(int i = 0; i < n; i++) val[i] *= -1;
	//for(int i = 0; i < n; i++)
    //    cout << lastbit[i] << '\n';
	for(ll k = 61; k >= 0; k--) {
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			if(lastbit[i] == k)
				sum += val[i];
		}
		if(sum > 0) {
			ans |= (1ll << k);
			for(int i = 0; i < n; i++) {
				if(mask[i] & (1ll << k))
					val[i] *= -1;
			}
		}
	}
	cout << ans << endl;
}