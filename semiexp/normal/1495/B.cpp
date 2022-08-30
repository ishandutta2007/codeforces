#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, P[202020];
int upl[202020], upr[202020];
int dwl[202020], dwr[202020];

bool check(int x, int y) {

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", P + i);
		--P[i];
	}
	upl[0] = 0;
	for (int i = 1; i < N; ++i) {
		if (P[i - 1] > P[i]) upl[i] = upl[i - 1] + 1;
		else upl[i] = 0;
	}
	upr[N - 1] = 0;
	for (int i = N - 2; i >= 0; --i) {
		if (P[i] < P[i + 1]) upr[i] = upr[i + 1] + 1;
		else upr[i] = 0;
	}

	int longest = 0;
	for (int i = 0; i < N; ++i) longest = max(longest, max(upl[i], upr[i]));

	int n_longest = 0;
	for (int i = 0; i < N; ++i) {
		if (longest == upl[i]) ++n_longest;
		if (longest == upr[i]) ++n_longest;
	}

	int ret = 0;
	for (int i = 1; i < N - 1; ++i) {
		if (!(P[i - 1] < P[i] && P[i] > P[i + 1])) continue;

		int p = i;
		while (p > 0 && P[p - 1] < P[p]) --p;

		int q = i;
		while (q < N - 1 && P[q] > P[q + 1]) ++q;

		if (n_longest != 2) continue;
		if (i - p != longest || q - i != longest) continue;
		// if (i - p < longest - 1 || q - i < longest - 1) continue;
		if (longest % 2 == 1) continue;
		++ret;
	}
	/*
	vector<pair<int, int>> cand;
	for (int i = 0; i < N; ++i) cand.push_back({max(upl[i], upr[i]), i});
	sort(cand.begin(), cand.end());
	reverse(cand.begin(), cand.end());
	cand.push_back({0, -1});

	int ret = 0;
	for (int i = 1; i < N - 1; ++i) {
		if (!(P[i - 1] < P[i] && P[i] > P[i + 1])) continue;

		int p = i;
		while (p > 0 && P[p - 1] < P[p]) --p;

		int q = i;
		while (q < N - 1 && P[q] > P[q + 1]) ++q;

		dwl[i] = i - p;
		dwr[i] = q - i;
		
		bool flg = true;
		flg = flg && check(i, p);
		if (p + 1 != i) flg = flg && check(i, p + 1);
		if (q - 1 != i) flg = flg && check(i, q - 1);
		flg = flg && check(i, q);

		int s = max(upl[p], upr[p]);
		int t = max(upl[q], upr[q]);
		int j = 0;
		if (cand[j] == make_pair(s, p) || cand[j] == make_pair(t, q)) ++j;
		if (cand[j] == make_pair(s, p) || cand[j] == make_pair(t, q)) ++j;
		if (max(dwl[i], dwr[i]) <= cand[j]) flg = false;

		if (flg) ++ret;
	}
	*/
	printf("%d\n", ret);
	return 0;
}