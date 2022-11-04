#include <bits/stdc++.h>

using namespace std;

int Tc, n, m;
char a[100], b[100];
#define MX 200005
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	for (cin >> Tc; Tc--; ) {
		cin >> n >> m;
		cin >> a >> b;
		int flg = 0;
		for (int i = 0; i < m - 1; i ++) {
			if (a[n - i - 1] != b[m - i - 1]) flg = 1;
		}
		int ff[4] = {0};
		for (int i = 0; i <= n - m; i ++) {
			if (a[i] == '0') ff[0] = 1;
			else ff[1] = 1;
		}
		if (ff[0] == 0 && b[0] == '0') flg = 1;
		if (ff[1] == 0 && b[0] == '1') flg = 1;
		if (!flg ) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 

	return 0;
}