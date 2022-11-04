#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;
int a[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		int res = -1, s, e;
		for (int i = 0; i < n; i ++) {
			int j = i;
			while (a[j] && j < n) j ++;
			int cnt2 = 0, sgn = 0;
			for (int k = i; k < j; k ++) {
				if (abs(a[k]) == 2) cnt2 ++;
				if (a[k] < 0) sgn ++;
			}
			if (sgn % 2 == 0) {
				if (cnt2 > res) {
					res = cnt2;
					s = i, e = j;	
				}
			}
			else {
				int val = cnt2;
				for (int k = i; k < j; k ++) {
					if (abs(a[k]) == 2) cnt2 --;
					if (a[k] < 0) {
						if (cnt2 > res) {
							res = cnt2;
							s = k + 1, e = j;	
						}
						break;
					}
				}
				cnt2 = val;
				for (int k = j - 1; k >= i; k --) {
					if (abs(a[k]) == 2) cnt2--;
					if (a[k] < 0) {
						if (cnt2 > res) {
							res = cnt2;
							s = i, e = k;
						}
					}
				}
			}
//			cout << i << ' ' << j << endl;
			i = j;
		}
		cout << s << ' ' << n - e << endl;
		cout << endl;
	}

	return 0;
}