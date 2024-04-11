#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<pair<long long, long long> > convex = { make_pair(0, 0) };
	long long lead = 0, tail = N;
	long long slope = 0, intercept = 0;
	for (int i = 0; i < Q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int x;
			cin >> x;
			lead += x;
			convex[0].first = -lead;
			convex[0].second = slope * lead - intercept;
		}
		else if (tp == 2) {
			int x;
			cin >> x;
			convex.push_back(make_pair(tail, -slope * tail - intercept));
			tail += x;
		}
		else {
			long long b, s;
			cin >> b >> s;
			b += lead * s;
			slope += s;
			intercept += b;
		}
		pair<long long, long long> last = convex.back(); convex.pop_back();
		while (convex.size() >= 2) {
			long double slope1 = (long double)(convex[convex.size() - 1].second - convex[convex.size() - 2].second) / (long double)(convex[convex.size() - 1].first - convex[convex.size() - 2].first);
			long double slope2 = (long double)(last.second - convex[convex.size() - 1].second) / (long double)(last.first - convex[convex.size() - 1].first);
			if (slope1 - 1.0e-9L >= slope2) convex.pop_back();
			else break;
		}
		convex.push_back(last);
		while (convex.size() >= 2) {
			long double slope1 = (long double)(convex[convex.size() - 1].second - convex[convex.size() - 2].second) / (long double)(convex[convex.size() - 1].first - convex[convex.size() - 2].first);
			if (slope1 + 1.0e-9L >= -slope) convex.pop_back();
			else break;
		}
		long long lc = convex[0].first * slope + convex[0].second + intercept;
		long long rc = convex.back().first * slope + convex.back().second + intercept;
		if (lc <= rc) cout << 1 << ' ' << lc << '\n';
		else cout << convex.back().first + lead + 1 << ' ' << rc << '\n';
	}
	return 0;
}