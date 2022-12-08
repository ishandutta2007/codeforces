#include <bits/stdc++.h>

using namespace std;

map<int, queue<int>> m;
vector<int> l;
vector<bool> u;
int cnt;
int point;

int main() {
//	freopen("in.txt", "r", stdin);
	int q;
	scanf("%d", &q);
	while (q--) {
		int o;
		scanf("%d", &o);
		if (o == 1) {
			int k;
			scanf("%d", &k);
			l.push_back(k);
			u.push_back(false);
			m[k].push(cnt);
			++cnt;
		} else if (o == 2) {
			while (u[point])
				++point;
			m[l[point]].pop();
			if (m[l[point]].empty())
				m.erase(l[point]);
			u[point] = true;
			printf("%d ", point + 1);
		} else {
			auto it = m.end();
			--it;
			int s = it->second.front();
			u[s] = true;
			printf("%d ", s + 1);
			it->second.pop();
			if (it->second.empty())
				m.erase(it);
		}
	}
	return 0;
}