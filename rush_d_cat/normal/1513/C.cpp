#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 200000 + 10;
LL f[12][N];

int main() {

	for (int i = 0; i < 10; i ++) f[i][0] = 1;

	for (int x = 1; x < N; x ++)
		for (int i = 0; i < 10; i ++) 
			if (i < 9)
				f[i][x] = f[i+1][x-1];
			else
				f[i][x] = (f[1][x-1] + f[0][x-1]) % mod;
	 

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		string s;
		int x;
		cin >> s >> x;
		LL ans = 0;
		for (auto c: s) {
			ans += f[c-'0'][x];
		}
		ans %= mod;
		cout << ans << endl;
	}
}