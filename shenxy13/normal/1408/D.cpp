#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int main() {
	int n, m, ans = 1000000000;
	scanf("%d %d", &n, &m);
	ii a[n], b[m];
	for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
	for (int i = 0; i < m; ++i) scanf("%d %d", &b[i].first, &b[i].second);
	sort(b, b + m);
	vector<ii> c;
	for (int i = 0; i < m; ++i) {
		while (!c.empty() && c.back().second < b[i].second) c.pop_back();
		c.push_back(b[i]);
	}
	multiset<int> hdiff;
	vector<iii> cry;
	hdiff.insert(0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < c.size(); ++j) {
			if (a[i].first > c[j].first) continue;
			if (j == 0 || a[i].first > c[j - 1].first) hdiff.insert(c[j].second - a[i].second + 1);
			cry.push_back(iii(c[j].first - a[i].first + 1, ii(i, j)));
		}
	}
	ans = min(ans, *--hdiff.end());
	sort(cry.begin(), cry.end());
	for (iii i: cry) {
		hdiff.erase(hdiff.find(c[i.second.second].second - a[i.second.first].second + 1));
		if (i.second.second + 1 != c.size()) hdiff.insert(c[i.second.second + 1].second - a[i.second.first].second + 1);
		ans = min(ans, i.first + *--hdiff.end());
	}
	printf("%d", ans);
	return 0;
}