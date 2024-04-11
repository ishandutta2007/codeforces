#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int R;
pair<int, int> pts[MAXN];

const int S = 1 << 20;
struct seg_node {
	int val = 0;
	int maxVal = 0;
} seg[2 * S];

void update(int a) {
	if (a >= S) {
		seg[a].maxVal = seg[a].val;
	} else {
		seg[a].maxVal = max(seg[2 * a].maxVal, seg[2 * a + 1].maxVal) + seg[a].val;
	}
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pts[i] = {x+y, x-y};
	}

	vector<int> ys;
	for (int i = 0; i < N; i++) {
		ys.push_back(pts[i].second - R);
		ys.push_back(pts[i].second + R + 1);
	}
	sort(ys.begin(), ys.end());
	ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
	vector<pair<int, pair<int, int>>> evts;
	for (int i = 0; i < N; i++) {
		int a = int(lower_bound(ys.begin(), ys.end(), pts[i].second - R) - ys.begin());
		int b = int(lower_bound(ys.begin(), ys.end(), pts[i].second + R + 1) - ys.begin());
		evts.emplace_back((pts[i].first - R) * 2, pair<int, int>(a, b));
		evts.emplace_back((pts[i].first + R) * 2 + 1, pair<int, int>(a, b));
	}
	sort(evts.begin(), evts.end());

	int ans = 0;
	for (auto it : evts) {
		int l, r; tie(l, r) = it.second;
		int v = (it.first % 2 == 0 ? +1 : -1);

		for (int a = l + S, b = r + S; a < b; a /= 2, b /= 2) {
			if (a & 1) {
				seg[a].val += v;
				seg[a].maxVal += v;
				a++;
			}
			if (b & 1) {
				b--;
				seg[b].val += v;
				seg[b].maxVal += v;
			}
		}
		for (int a = l + S; a; a /= 2) update(a);
		for (int a = r + S; a; a /= 2) update(a);

		ans = max(ans, seg[1].maxVal);
	}
	cout << ans << '\n';

	return 0;
}