#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MX = 100005;
const LL mod = 1e9 + 7;

int Tc, N;
int n, k;
LL bit[40];

void init () {
	bit[0] = 1;
	for (int i = 1; i < 40; i++) bit[i] = bit[i - 1] * 2;
	
}

LL mod_exp (int a, int nn) {
	if (nn == 0) return 1;
	return mod_exp (a, nn - 1) * a % mod;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("I", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init ();
	
	int i, j;
	
	for (cin >> Tc; Tc--; ) {
		cin >> n >> k;
//		k++;
		int cnt = 0;
		while (k >= bit[cnt]) cnt++;
		cnt --;
//		cout << cnt << ' ' << bit[cnt] << endl;
		LL rlt = 0;
		for (int i = cnt; i >= 0; i--) {
			if (k < bit[i]) continue;
			rlt += mod_exp (n, i);
			rlt %= mod;
			k -= bit[i];
		}
		cout << rlt << endl;
	}

	return 0;

}