#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 100010;

int pfac[NMAX];

ll byKFreePart[NMAX];
int kFreeConjugate[NMAX];
int kFreePart[NMAX];

void fillWithPFactors(int x, map<int, int> &m) {
	if (x == 1) return;
	++m[pfac[x]];
	fillWithPFactors(x/pfac[x], m);
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 2; i < NMAX; ++i) pfac[i] = i;
	for (int i = 2; i < NMAX; ++i) {
		if (pfac[i] < i) continue;
		for (int toMark = 2 * i; toMark < NMAX; toMark += i) pfac[toMark] = i;
	}
	for (int i = 1; i < NMAX; ++i) {
		map<int, int> cpf; fillWithPFactors(i, cpf);
		for (auto &p_e : cpf) p_e.second %= k;
		kFreePart[i] = 1;
		for (auto p_e : cpf) {
			for (int k = 0; k < p_e.second; ++k) kFreePart[i] *= p_e.first;
		}
		for (auto &p_e : cpf) p_e.second = (k - p_e.second) % k;
		ll cprod = 1;
		for (auto p_e : cpf) {
			for (int k = 0; k < p_e.second && cprod < NMAX; ++k) cprod *= p_e.first;
		}
		if (cprod < NMAX) kFreeConjugate[i] = cprod;
		else kFreeConjugate[i] = -1;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		if (kFreeConjugate[x] > -1) ans += byKFreePart[kFreeConjugate[x]];
		++byKFreePart[kFreePart[x]];
	}
	printf("%lld\n", ans);
	return 0;
}