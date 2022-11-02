#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	int sum = 0;
	map<long long, vector<pair<long long, long long> > > d;
	map<pair<long long, long long>, int> penalty;
	for (int i = 0; i < Q; ++i) {
		int tp; long long x, y;
		cin >> tp >> x >> y;
		long long norm = x * x + y * y;
		if (tp == 1) {
			++sum;
			vector<pair<long long, long long> > v = d[norm];
			for (pair<long long, long long> i : v) {
				long long tx = i.first + x, ty = i.second + y;
				long long g = gcd(tx, ty);
				penalty[make_pair(tx / g, ty / g)] += 2;
			}
			long long sg = gcd(x, y);
			penalty[make_pair(x / sg, y / sg)] += 1;
			d[norm].push_back(make_pair(x, y));
		}
		if (tp == 2) {
			--sum;
			vector<pair<long long, long long> > v = d[norm];
			v.erase(find(v.begin(), v.end(), make_pair(x, y)));
			for (pair<long long, long long> i : v) {
				long long tx = i.first + x, ty = i.second + y;
				long long g = gcd(tx, ty);
				penalty[make_pair(tx / g, ty / g)] -= 2;
			}
			long long sg = gcd(x, y);
			penalty[make_pair(x / sg, y / sg)] -= 1;
			d[norm] = v;
		}
		if (tp == 3) {
			long long g = gcd(x, y);
			cout << sum - penalty[make_pair(x / g, y / g)] << '\n';
		}
	}
	return 0;
}