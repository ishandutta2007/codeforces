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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct State {
	int l, r;
	int addH, addV;
	State() {
		l = r = addH = addV = 0;
	}
	State(int l, int r, int addH, int addV) : l(l), r(r), addH(addH), addV(addV) {}

	bool operator < (const State &other) const {
		return l < other.l;
	}
};

set < State > S;
unordered_set < int > used;

char s[10];

void add(State s) {
	if (s.l <= s.r) {
		S.insert(s);
	}
}

int process(int x, int y, char s) {
	set < State > ::iterator it = S.upper_bound(State(y, y, 0, 0));
	State current;
	if (it == S.end()) {
		current = *S.rbegin();
	} else {
		--it;
		current = *it;
	}

	S.erase(current);

	if (s == 'U') {
		State L(current.l, y, current.addH + (current.r - y), current.addV);
		State R(y + 1, current.r, current.addH, 0);
		add(L);
		add(R);
		return current.r - y + 1 + current.addH;
	} else {
		State L(current.l, y - 1, 0, current.addV);
		State R(y, current.r, current.addH, current.addV + (y - current.l));
		add(L);
		add(R);
		return y - current.l + 1 + current.addV;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	S.insert(State(1, n, 0, 0));

	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &y, &x);
		scanf("%s", &s);
		if (used.count(x)) {
			printf("0\n");
			continue;
		}
		used.insert(x);

		int res = process(x, y, s[0]);
		printf("%d\n", res);
	}



	return 0;
}