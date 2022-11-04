#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;

int a[2005];
int b[2005], c[2005];
int sum;

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		b[0] = a[0];
		for (int i = 1; i < n; i++) b[i] = b[i - 1] ^ a[i];
		sum = b[n - 1];
		c[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) c[i] = c[i + 1] ^ a[i];
		bool flg = 0;
		for (int i = 0; i < n - 1; i++) {
			if (b[i] == c[i + 1]) {
				flg = 1;
				break;
			}
			if (b[i] != sum) continue;
			for (int j = n - 1; j > i + 1; j--) if (b[i] == c[j]) {
				flg = 1;
				break;
			}
			if (flg) break;
		}
		if (flg) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;

}