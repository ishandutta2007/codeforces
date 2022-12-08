#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m;

bool ok[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	ll ans = 0LL;
	for (int i = 0; i < m; i++) {
		for (int j = 0;  j < m; j++) {
			ll cur = i*i + j*j;
			if (cur%m == 0) {
				ok[i][j] = true;

				ll f1 = n/m;
				ll res = n - m * (n/m);
				if (i != 0 && i <= res) f1+=1LL;

				ll f2 = n/m;

				if (j != 0 &&  j <= res) f2+=1LL;

				ans += f1*f2;

			}
		}
	}
	cout << ans << endl;

}