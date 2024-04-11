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

int N, A[26], S;

char buf[101010];

void show(char c, int t)
{
	if (t == 0) return;
	for (int i = 0; i < t; ++i) buf[i] = c;
	buf[t] = '\0';
	printf("%s", buf);
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	scanf("%d", &N); S = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		S += A[i];
	}

	if (S % 2 == 1) {
		int odd = -1;
		for (int i = 0; i < N; ++i) if (A[i] % 2 == 1) {
			if (odd == -1) odd = i;
			else odd = -2;
		}

		if (odd < 0) {
			puts("0");
			for (int i = 0; i < N; ++i) show('a' + i, A[i]);
			puts("");
		} else {
			int g = 0;
			for (int i = 0; i < N; ++i) g = gcd(g, A[i]);

			printf("%d\n", g);
			string tmp;
			for (int i = 0; i < N; ++i) if (i != odd) {
				for (int j = 0; j < A[i] / g / 2; ++j) tmp.push_back('a' + i);
			}
			for (int j = 0; j < A[odd] / g; ++j) tmp.push_back('a' + odd);
			for (int i = N - 1; i >= 0; --i) if (i != odd) {
				for (int j = 0; j < A[i] / g / 2; ++j) tmp.push_back('a' + i);
			}

			for (int i = 0; i < g; ++i) printf("%s", tmp.c_str());
			puts("");
		}
		return 0;
	}

	int g = 0;
	for (int i = 0; i < N; ++i) g = gcd(g, A[i]);

	if (g % 2 != 0) {
		puts("0");
		for (int i = 0; i < N; ++i) show('a' + i, A[i]);
		puts("");
	} else {
		printf("%d\n", g);
		string tmp;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < A[i] / g; ++j) tmp.push_back('a' + i);
		}
		for (int i = N - 1; i >= 0; --i) {
			for (int j = 0; j < A[i] / g; ++j) tmp.push_back('a' + i);
		}
		for (int i = 0; i < g / 2; ++i) printf("%s", tmp.c_str());
		puts("");
	}

	return 0;
}