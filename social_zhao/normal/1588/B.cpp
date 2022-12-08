#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, ansi, ansj, ansk;

int ask(int l, int r) { cout << "? " << l << " " << r << endl; int x; cin >> x; return x; }
void guess(int i, int j, int k) { cout << "! " << i << " " << j << " " << k << endl; }
int GetSol(int inv) { return (int)(1 + sqrt(1 + 8 * inv)) / 2; }
int GetInv(int x) { return (x - 1) * x / 2; }

void solve() {
	cin >> n;
	int l = 1, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(!ask(1, mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	assert(ans != -1);
	ansi = ans;
	int tot = ask(1, n), lft = ask(ansi, ansi + 1), rht = ask(ansi + 2, n);
		int delt = tot - lft - rht, lenA = 2 + delt / 2, lenB = GetSol(tot - GetInv(lenA));
		ansj = ansi + lenA, ansk = ansj + lenB - 1;
	if(ansj == ansk) ansk--, ansj = ansi, ansi--;
	guess(ansi, ansj, ansk);
}

main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}