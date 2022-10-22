#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	vector <pair <int, int>> segs;
	int l = 0;
	for (int i = 1; i < n - 1; ++i) {
		if ((p[i] > p[i - 1]) != (p[i + 1] > p[i])) {
			segs.pb({l, i});
			l = i;
		}
	}
	segs.pb({l, n - 1});

	set <pair <int, pair <int, int>>> q;
	for (auto t : segs) {
		int len = t.y - t.x + 1;
		int l = t.x, r = t.y;
		//cout << l << " " << r << endl;
		q.insert({-len, {l, r}});
	}

	int res = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (p[i - 1] > p[i] || p[i + 1] > p[i]) {
			continue;
		}
		int lt = 1, rt = 1;
		int now = i - 1;
		while (now != -1 && p[now] < p[now + 1]) {
			--now;
			++lt;
		}
		now = i + 1;
		while (now < n && p[now] < p[now - 1]) {
			++now;
			++rt;
		}
		auto it = q.begin();
		while (it != q.end()) {
			int l = (it->y).x;
			int r = (it->y).y;
			//cout << l << " " << r << endl;
			if (l <= i && i <= r) {
				++it;
				continue;
			}
			break;
		}
		int maxd = 0;
		if (it != q.end()) {
			maxd = max(maxd, -it->x);
		}
		//cout << i << " " << lt << " " << rt << " " << maxd << endl;
		if (lt > max(maxd, rt - rt % 2) && rt > max(maxd, lt - lt % 2)) {
			++res;
		}
	}
	cout << res << "\n";
}