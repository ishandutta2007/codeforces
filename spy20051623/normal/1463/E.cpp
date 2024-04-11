#include <bits/stdc++.h>
using namespace std;
int in[300005];
int fa[300005];
int la[300005];
int ne[300005];
vector<int> e[300005];
vector<int> res;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k, i, j, p;
	bool f;
	n = read();
	k = read();
	for (i = 1; i <= n; ++i) {
		fa[i] = read();
	}
	while (k--) {
		i = read();
		j = read();
		la[j] = i;
		if (!ne[i])
			ne[i] = j;
		else {
			cout << 0 << endl;
			return 0;
		}
	}
	for (i = 1; i <= n; ++i) {
		if (la[i])
			continue;
		j = i;
		while (ne[j]) {
			j = ne[j];
			if (j == i) {
				cout << 0 << endl;
				return 0;
			}
			if (la[fa[j]] != i && fa[j] != i) {
				++in[i];
				e[fa[j]].push_back(i);
			}
			la[j] = i;
		}
		++in[i];
		e[fa[i]].push_back(i);
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i : e[p]) {
			--in[i];
			if (!in[i]) {
				res.push_back(i);
				q.push(i);
				j = ne[i];
				while (j) {
					res.push_back(j);
					q.push(j);
					j = ne[j];
				}
			}
		}
	}
	if (res.size() < n)
		cout << 0 << endl;
	else
		for (i = 0; i < res.size(); ++i) {
			cout << res[i] << ' ';
		}
	return 0;
}