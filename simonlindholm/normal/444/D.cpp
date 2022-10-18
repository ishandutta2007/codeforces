#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

string s;
map<string, vector<int> > positions;
int solve(const string& a, const string& b) {
	if (!positions.count(a) || !positions.count(b))
		return -1;
	vector<int>& pa = positions[a];
	vector<int>& pb = positions[b];
	if (pa.size() > pb.size())
		return solve(b, a);
	int res = 1 << 29;
	for (int i : pa) {
		vector<int>::iterator it = lower_bound(pb.begin(), pb.end(), i);
		if (it != pb.end()) {
			int j = *it;
			int start = min(i, j);
			int end = max(i + (int)a.size(), j + (int)b.size());
			res = min(res, end - start);
		}
		if (it != pb.begin()) {
			--it;
			int j = *it;
			int start = min(i, j);
			int end = max(i + (int)a.size(), j + (int)b.size());
			res = min(res, end - start);
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = 1; j <= 4; ++j) {
			if (i + j <= (int)s.size()) {
				string s2 = s.substr(i, j);
				positions[s2].push_back(i);
			}
		}
	}
	for (auto& pa : positions) {
		sort(pa.second.begin(), pa.second.end());
	}
	int Q;
	cin >> Q;
	string a, b;
	map<string, int> memo;
	for (int i = 0; i < Q; ++i) {
		cin >> a >> b;
		int& res = memo[a + "|" + b];
		if (!res)
			res = solve(a, b) + 2;
		cout << res - 2 << endl;
	}
	return 0;
}