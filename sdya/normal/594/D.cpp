#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const int maxD = 470;
const long long P = 1000000007LL;

long long inv(long long x) {
	long long x1 = 1, b1 = x;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(b1, b2);
		swap(x1, x2);
	}
	x1 %= P;
	if (x1 < 0) {
		x1 += P;
	}
	return x1;
}

int n, m;
int a[maxN];
vector < int > p[maxN];
int l[maxN], r[maxN];
vector < int > order[maxD];
int ans[maxN];

long long s[maxN];

bool comp(int x, int y) {
	return r[x] < r[y];
}

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int primes[maxN], cntp;

vector < int > factor(int n) {
	vector < int > res;
	for (int i = 0; i < cntp; ++i) {
		int q = 0;
		while (n % primes[i] == 0) {
			++q;
			n /= primes[i];
		}
		if (q > 0) {
			res.push_back(primes[i]);
		}
	}
	if (n > 1) {
		res.push_back(n);
	}
	return res;
}

const int maxL = 1100000;
int cnt[maxL];
bool isp[maxL];
int rev[maxL];
int rev2[maxL];

void addIndex(int index, long long &v) {
	for (int i = 0; i < p[index].size(); ++i) {
		++cnt[p[index][i]];
		if (cnt[p[index][i]] == 1) {
			v = (v * rev[p[index][i]]) % P;
		}
	}
}

void removeIndex(int index, long long &v, bool nov = false) {
	if (nov) {
		for (int i = 0; i < p[index].size(); ++i) {
			cnt[p[index][i]] = 0;
		}
	} else {
		for (int i = 0; i < p[index].size(); ++i) {
			--cnt[p[index][i]];
			if (cnt[p[index][i]] == 0) {
				v = (v * rev2[p[index][i]]) % P;
			}
		}
	}
}

long long getScore(int l, int r) {
	long long res = s[r];
	if (l == 0) {
		return res;
	}
	return (res * inv(s[l - 1])) % P;
}

void process(int index) {
	int v = order[index][0];
	long long coef = 1LL;
	for (int i = l[v]; i <= r[v]; ++i) {
		addIndex(i, coef);
	}

	ans[v] = (getScore(l[v], r[v]) * coef) % P;
	int cl = l[v], cr = r[v];
	for (int i = 1; i < order[index].size(); ++i) {
		int v = order[index][i];
		for (int j = cr + 1; j <= r[v]; ++j) {
			addIndex(j, coef);
		}
		if (l[v] <= cl) {
			for (int j = l[v]; j < cl; ++j) {
				addIndex(j, coef);
			}
		} else {
			for (int j = cl; j < l[v]; ++j) {
				removeIndex(j, coef);
			}
		}
		ans[v] = (getScore(l[v], r[v]) * coef) % P;
		cl = l[v];
		cr = r[v];
	}
	for (int i = cl; i <= cr; ++i) {
		removeIndex(i, coef, true);
	}
}

void gen() {
	int n = 200000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", (rand() * rand() + rand()) % 1000000 + 1);
	}
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		int l = (rand() * rand() + rand()) % n + 1;
		int r = (rand() * rand() + rand()) % n + 1;
		if (l > r) {
			swap(l, r);
		}
		printf("%d %d\n", l, r);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;

	cntp = 0;
	for (int i = 2; i <= 1000; ++i) {
		if (isPrime(i)) {
			primes[cntp++] = i;
		}
	}

	for (int i = 2; i * i < maxL; ++i) {
		if (!isp[i]) {
			for (int j = i * i; j < maxL; j += i) {
				isp[j] = true;
			}
		}
	}

	for (int i = 2; i < maxL; ++i) {
		if (!isp[i]) {
			rev[i] = ((long long)(i - 1) * inv(i)) % P;
			rev2[i] = inv(rev[i]);
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s[i] = a[i];
		if (i > 0) {
			s[i] = (s[i] * s[i - 1]) % P;
		}
		p[i] = factor(a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		--l[i];
		--r[i];
		order[l[i] / maxD].push_back(i);
	}
	for (int i = 0; i < maxD; ++i) {
		sort(order[i].begin(), order[i].end(), comp);
	}

	for (int i = 0; i < maxD; ++i) {
		if (order[i].size() == 0) {
			continue;
		}
		process(i);
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}

	cerr << clock() << endl;

	return 0;
}