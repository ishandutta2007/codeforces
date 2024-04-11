#include <iostream>
#define MAXN 200000
using namespace std;

int BIT[MAXN*3+1];
int BIT2[MAXN*3+1];

int query(int bit[], int cur) {
	int sum = 0;
	while (cur > 0) {
		sum += bit[cur];

		cur -= cur & (-cur);
	}
	return sum;
}

void update(int bit[], int cur, int n, int val) {
	while (cur <= n) {
		bit[cur]+=val;
		// cout << " --- " << bit[cur] << endl;
		cur += cur & (-cur);
	}
}

int main() {
	for (int i = 0; i <= MAXN*2; i++) {
		BIT[i] = 0;
		BIT2[i] = 0;
	}
	int n, k, q;
	cin >> n >> k >> q;
	int l, r;
	for (int i = 0; i  < n; i++) {
		cin >> l >> r;
		update(BIT, l, MAXN, 1);
		update(BIT, r+1, MAXN, -1);
	}
	int temp;
	for (int i = 1; i <= MAXN; i++) {
		temp = query(BIT, i);
		// if (i <= 100) {
		// 	cout << i << " : " << temp << endl;
		// }
		if (temp >= k) {
			update(BIT2, i, MAXN, 1);
		}
	}
	int a,b;
	int ans;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		ans = query(BIT2, b) - query(BIT2, a-1);
		cout << ans << endl;
	}
	// cin >> a;

}