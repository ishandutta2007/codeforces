#include<bits/stdc++.h>

using namespace std;
#define tii tuple<int, int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, m;
	cin >> n >> q >> m;
	vector<tii> qu;
	int nums[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int t, l, r;
	for (int i = 0; i < q; i++) {
		cin >> t >> l >> r;
		qu.push_back(make_tuple(t, l, r));
	}
	reverse(qu.begin(), qu.end());
	int cur;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		for (int i = 0; i < qu.size(); i++) {
			t = get<0>(qu[i]);
			l = get<1>(qu[i]);
			r = get<2>(qu[i]);
			if (t == 1) {
				if (cur == l) cur = r;
				else if (cur > l && cur <= r) cur--;
			}
			else {
				if (cur >= l && cur <= r) {
					cur = r-cur+l;
				}
			}
		}
		cout << nums[cur] << " ";
	}
	cout << endl;
	cin >> n;
}