#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct query {
	int l, r, id;
};
struct compr : public binary_function<query, query, bool> {
	bool operator()(query q1, query q2) {
		return q1.r > q2.r;
	}
};
int n, m, c, x;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<string> s(n);
	vector<query> v;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> c;
		for (int j = 0; j < c; j++) {
			cin >> x; x--;
			v.push_back(query{ x, x + (int)s[i].size(), i });
			m = max(m, x + (int)s[i].size());
		}
	}
	vector<vector<int> > vd(m);
	for (int i = 0; i < v.size(); i++) vd[v[i].l].push_back(i);
	priority_queue<query, vector<query>, compr> que;
	string ret;
	for (int i = 0; i < m; i++) {
		while (!que.empty() && que.top().r == i) que.pop();
		for (int j : vd[i]) que.push(v[j]);
		if (que.empty()) ret += 'a';
		else {
			query t = que.top();
			ret += s[t.id][i - t.l];
		}
	}
	cout << ret << endl;
	return 0;
}