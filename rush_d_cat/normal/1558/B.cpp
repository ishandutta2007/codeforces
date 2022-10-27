#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4000000 + 10;

int n, m;
int sum[N];

void upd(int pos, int x) {
	(sum[pos+1] += x) %= m;
	//printf("# add %d %d %d\n",pos+1,n,x);
	for (int i = 2;; i ++) {
		int l = i * pos, r = i * (pos + 1) - 1;
		if (l > n) break;
		r = min(r, n);
		//printf("add [%d,%d] %d\n", l, r, x);
		(sum[l] += x) %= m;
		(sum[r+1] -= x) %= m;
		sum[r+1] = (sum[r+1]%m+m) % m;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m;
	upd(1, 1); sum[1] = 1;
	int tot = 0;
	for (int i = 2; i <= n; i ++) {
		tot = (tot + sum[i]) % m;
		upd(i, tot);
		if (i == n) {
			cout << tot << "\n";
		}
	}
}