#include <bits/stdc++.h>
const int N = 5e5 + 9;
using namespace std;
multiset<int, greater<int>> lset;
// priority_queue <int, vector<int>, less<int> > pq;
int q;
int a[N], bcur[N];
vector<int> b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(bcur, 0, sizeof(bcur));
	cin >> q;
	int cur = 0, cnt = 0;
	a[0] = 0;
	for (int i = 0; i < q; ++i) {
		// cout << "Debug: " << i << " qp: ";
		// for (auto qp: lset) {
		// 	cout << qp << ' ' ;
		// }cout << endl;
		int op;
		cin >> op;
		if (op == 1) {
			int m;
			cin >> m;
			a[++cnt] = m;
			b[m].push_back(cnt);
			lset.insert(m);
		}
		else if (op == 2) {

			while(a[cur] == 0)
				++ cur;
			int tcost = a[cur];
			// cout << i << ' ' << tcost << '\n';
			a[cur] = 0;
			int ans = cur;
			bcur[tcost]++;
			lset.erase(lset.find(tcost));
			cout << ans << ' ';
		}
		else if (op == 3) {
			int tcost = *(lset.begin());
			lset.erase(lset.begin());
			int ans = b[tcost][bcur[tcost]];
			bcur[tcost]++;
			cout << ans << ' ';
			a[ans] = 0;
		}
	}
}