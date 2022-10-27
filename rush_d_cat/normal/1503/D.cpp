#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector< vector<int> > f(n+1);
	for (int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;
		if (min(x, y) >= n+1 || max(x, y) <= n) {
			cout << -1 << endl; return 0;
		}
		f[min(x,y)] = {max(x, y), x>y};
	}

	vector<int> premin(n+2,1e9), sufmax(n+2,0);

	for (int i = 1; i <= n; i ++)
		premin[i] = min(premin[i-1], f[i][0]);
	for (int i = n; i >= 1; i --)
		sufmax[i] = max(sufmax[i+1], f[i][0]);
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i = j) {
		while (j <= n && premin[j] < sufmax[j+1]) j ++;
		assert(j <= n);
		j ++;
		
		int l1=1e9,l2=1e9,tmpans=0;
		for (int x = i; x < j; x ++) {
			if (f[x][0] < l1) {
				l1 = f[x][0]; 
				if (f[x][1] == 1) tmpans ++;
			} else if (f[x][0] < l2) {
				l2 = f[x][0];
				if (f[x][1] == 0) tmpans ++;
			} else {
				cout << -1 << endl; return 0;
			}
		}
		ans += min(tmpans, j-i-tmpans);
	}
	cout << ans << endl;
}