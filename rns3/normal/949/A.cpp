#include <bits/stdc++.h>
using namespace std;

#define N 202020

char s[N];

int n;

set <int> x;
set <int> y;
set <int> :: iterator it;

vector <int> v[N];

int main() {
	gets(s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '0') x.insert(i);
		else y.insert(i);
	}
	int m = 0;
	int last;
	while (!x.empty() || !y.empty()) {
		if (x.empty()) {
			puts("-1");
			return 0;
		}
		m ++;
		it = x.begin();
		last = *it;
		v[m].push_back(last);
		x.erase(it);
		while (1) {
			it = y.lower_bound(last);
			if (it == y.end()) break;
			int tmp = *it;
			it = x.lower_bound(tmp);
			if (it == x.end()) break;
			last = *it;
			y.erase(tmp);
			x.erase(it);
			v[m].push_back(tmp);
			v[m].push_back(last);
		}
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; i ++) {
		printf("%d", (int)v[i].size());
		for (int j = 0; j < v[i].size(); j ++) printf(" %d", v[i][j]);
		puts("");
	}


	return 0;
}