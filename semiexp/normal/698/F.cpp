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

int N, P[1010101];

int divisor[1010101];
vector<int> primes;
int pmap[1010101];
int freedom[1010101];
int isos[1010101];

int canonize(int n)
{
	int ret = 1, lp = -1;
	while (n > 1) {
		if (lp != divisor[n]) ret *= divisor[n];
		lp = divisor[n];
		n /= divisor[n];
	}
	return ret;
}

vector<int> factorize(int n)
{
	vector<int> ret; int lp = -1;
	while (n > 1) {
		if (lp != divisor[n]) ret.push_back(divisor[n]);
		lp = divisor[n];
		n /= divisor[n];
	}
	return ret;
}

int sz(int p)
{
	return (p == 1 ? 1 : (N / p));
}
bool eq(int p, int q)
{
	return sz(p) == sz(q);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", P + i);

	// if N <= 3? any permutation is OK
	if (N <= 3) {
		int a = 0;
		for (int i = 1; i <= N; ++i) if (P[i] == 0) ++a;
		int ret = 1;
		for (int i = 1; i <= a; ++i) ret *= i;
		printf("%d\n", ret);
		return 0;
	}

	divisor[1] = 1; pmap[1] = -1;
	for (int i = 2; i <= N; ++i) divisor[i] = i;
	for (int i = 2; i <= N; ++i) if (divisor[i] == i) {
		primes.push_back(i);
		pmap[i] = -1;
		if (i > 2000) continue;
		for (int j = i * i; j <= N; j += i) {
			if (divisor[j] == j) divisor[j] = i;
		}
	}

	i64 ret = 1;

	for (int i = 1; i <= N; ++i) if (P[i] != 0) {
		vector<int> fa = factorize(i), fb = factorize(P[i]);
		if (fa.size() == 0) fa.push_back(1);
		if (fb.size() == 0) fb.push_back(1);
		if (fa.size() != fb.size()) {
			goto impossible;
		}
		for (int j = 0; j < fa.size(); ++j) {
			if (!eq(fa[j], fb[j])) goto impossible;
			if (pmap[fa[j]] != -1 && pmap[fa[j]] != fb[j]) goto impossible;
			pmap[fa[j]] = fb[j];
		}
	}

	for (int i = 1; i <= N; ++i) freedom[i] = isos[i] = 0;
	for (int i = 1; i <= N; ++i) if (divisor[i] == i && pmap[i] == -1) {
		freedom[sz(i)]++;
	}

	for (int i = 1; i <= N; ++i) if (freedom[i] > 1) {
		for (int j = 1; j <= freedom[i]; ++j) ret = (ret * j) % MOD;
	}

	for (int i = 1; i <= N; ++i) if (P[i] == 0) {
		int c = canonize(i);
		++isos[c];
	}

	for (int i = 1; i <= N; ++i) if (isos[i] > 1) {
		for (int j = 1; j <= isos[i]; ++j) ret = (ret * j) % MOD;
	}

	printf("%d\n", (int)ret);
	return 0;

impossible:
	puts("0");
	return 0;
}