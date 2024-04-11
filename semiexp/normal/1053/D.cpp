#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
int fc[2020202];
int cnt[2020202];
int deg[2020202], degc[2020202];
i64 ans;

void use(int m) {
	while (m >= 2) {
		int p = fc[m];
		int d = 0;
		while (m % p == 0) {
			m /= p;
			++d;
		}
		if (deg[p] == d) {
			++degc[p];
		} else if (deg[p] < d) {
			degc[p] = 1;
		}
		while (deg[p] < d) {
			ans = ans * p % MOD;
			++deg[p];
		}
	}
}

bool chk(int m) {
	while (m >= 2) {
		int p = fc[m];
		int d = 0;
		while (m % p == 0) {
			m /= p;
			++d;
		}
		if (deg[p] == d && degc[p] == 1) return false;
	}
	return true;
}

int main()
{
	for (int i = 2; i < 2020202; ++i) fc[i] = i;

	for (int i = 2; i < 2020202; ++i) {
		if (fc[i] == i) {
			if (i < 5000) {
				for (int j = i * i; j < 2020202; j += i) {
					if (fc[j] == j) fc[j] = i;
				}
			}
		}
	}

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}

	bool app = false;

	vector<int> used;
	ans = 1;
	for (int i = 2020200; i >= 2; --i) {
		if (cnt[i] >= 3) app = true;
		if (cnt[i] >= 2) {
			use(i);
			use(i - 1);
			used.push_back(i);
			used.push_back(i - 1);
		} else if (cnt[i] == 1) {
			if (deg[i] == 0) {
				use(i);
				used.push_back(i);
			} else {
				use(i - 1);
				used.push_back(i - 1);
			}
		}
	}
	for (int u : used) {
		if (chk(u)) app = true;
	}
	if (app) ADD(ans, 1);
	printf("%lld\n", ans);

	return 0;
}