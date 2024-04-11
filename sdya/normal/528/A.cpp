#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void update(set < pair < int, int > > &x, multiset < int > &y, int value) {
	set < pair < int, int > > ::iterator it = x.lower_bound(make_pair(value, -1));
	pair < int, int > p;
	if (it == x.end()) {
		p = *x.rbegin();
	} else {
		--it;
		p = *it;
	}

	y.erase(y.find(p.second - p.first));
	x.erase(p);

	x.insert(make_pair(p.first, value));
	x.insert(make_pair(value, p.second));
	y.insert(value - p.first);
	y.insert(p.second - value);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	set < pair < int, int > > x, y;
	multiset < int > u, v;
	x.insert(make_pair(0, h));
	y.insert(make_pair(0, w));
	u.insert(h);
	v.insert(w);
	char s[10];
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s);
		int t;
		scanf("%d", &t);
		if (s[0] == 'H') {
			update(x, u, t);
		} else {
			update(y, v, t);
		}

		long long a = *u.rbegin();
		long long b = *v.rbegin();
		printf("%I64d\n", a * b);
	}


	return 0;
}