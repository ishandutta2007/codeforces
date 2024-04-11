#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define ld long double
#define mt make_tuple

priority_queue<tuple<ld, int, int>> pq;
int n, m, r, k;
ld ops;
set<pii> seen;

ld exp(int i, int j) {
	ld ans = 0.0;
	// cout << "here   " << i << "   " << j << "  "
	//  << i+r-1 << " " << i-r+1 << endl;
	ans = (min(i, n-r+1)-max(1, i-r+1)+1.0) * 
		(min(j,m-r+1) - max(1, j-r+1)+1.0);
	// cout << "        " << i << "   " << j << "    " << min(i, n-r+1)-max(1, i-r+1) << endl;
	ans = ans/ops;
	return ans;
}

void ins(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m) return;
	pii tempo = pii(x, y);
	if (seen.count(tempo) > 0) return;
	seen.insert(tempo);
	pq.push(mt(exp(x, y), x, y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> r >> k;
	ops = (n-r+1.0)*(m-r+1.0);
	// cout << "ops   " << ops << endl;
	ld ans = 0.0;
	ins((n+1)/2, (m+1)/2);
	while (k--) {
		tuple<ld, int, int> cur = pq.top();
		pq.pop();
		ans += get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);
		// cout << "X  " << x << " " << y << " " << get<0>(cur) << endl;

		ins(x+1, y);
		ins(x-1, y);
		ins(x, y+1);
		ins(x, y-1);
	}
	cout << fixed << setprecision(15);
	cout << ans << endl;
	cin >> n;

}