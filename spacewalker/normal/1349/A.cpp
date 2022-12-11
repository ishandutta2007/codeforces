#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 200010;

vector<int> inArrDivBy[NMAX];
int spDiv[NMAX];

void factorize(int i, map<int, int> &facs) {
	if (i <= 1) return;
	facs[spDiv[i]]++;
	factorize(i / spDiv[i], facs);
}

int main() {
	for (int i = 2; i < NMAX; ++i) spDiv[i] = i;
	for (int i = 2; i < NMAX; ++i) {
		if (spDiv[i] == i) {
			for (int toMark = 2*i; toMark < NMAX; toMark += i) spDiv[toMark] = i;
		}
	}
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		map<int, int> cfac;
		int x; scanf("%d", &x);
		factorize(x, cfac);
//		for (auto p_e : cfac) printf("pair %d %d\n", p_e.first, p_e.second);
		for (auto p_e : cfac) inArrDivBy[p_e.first].push_back(p_e.second);
	}
//	printf("HERE\n");
	ll ans = 1;
	for (int i = 2; i < NMAX; ++i) {
//		printf("proc %d\n", i);
//		printf("size %lu\n", inArrDivBy[i].size());
		if (spDiv[i] < i || inArrDivBy[i].size() < n - 1) continue;
		int curExp = 0;
		if (inArrDivBy[i].size() == n - 1) curExp = *min_element(begin(inArrDivBy[i]), end(inArrDivBy[i]));
		else {
			sort(begin(inArrDivBy[i]), end(inArrDivBy[i]));
			curExp = inArrDivBy[i][1];
		}
		for (int k = 0; k < curExp; ++k) ans *= i;
	}
	printf("%lld\n", ans);
	return 0;
}