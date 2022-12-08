#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	char c;
	bool bound = false;
	ll ans[N+1][5011];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 5010; j++) {
			ans[i][j] = 0LL;
		}
	}
	ans[0][0] = 1LL;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		if (c == 'f') {
			if (bound) {
				for (int j =1; j <= 5010; j++) {
					ans[i][j] = ans[i-1][j-1];
				}
			}
			else {
				ll csum = 0LL;
				for (int j = 5010; j >= 0; j--) {
					csum = (csum+ans[i-1][j])%mod;
					ans[i][j] = csum;
				}
				// ans[i][0] = 0LL;
				for (int j = 5010; j >= 0; j--) {
					ans[i][j] = ans[i][j-1];
				}
				ans[i][0] = 0LL;
			}
			bound = true;
		}
		else {
			
			if (bound) {
				for (int j =0; j <= 5010; j++) {
					ans[i][j] = ans[i-1][j];
				}
			}
			else {
				ll csum = 0LL;
				for (int j = 5010; j >= 0; j--) {
					csum = (csum+ans[i-1][j])%mod;
					ans[i][j] = csum;
				}
			}
			bound = false;
		}
		// ll fin = 0LL;
		// for (int j = 0; j <= 5010; j++) {
		// 	fin = (fin+ans[N][i])%mod;
		// }
		// cout << "--->   " << fin << endl;
	}
	ll fin = 0LL;
	for (int i = 0; i <= 5010; i++) {
		fin = (fin+ans[N][i])%mod;
	}
	cout << fin << endl;
	cin >> fin;
}