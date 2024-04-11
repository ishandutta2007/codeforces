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

vector<bool> op;
int N;

int dmod(int a, int b)
{
	return (b - (-a) % b) % b;
}
int ddiv(int a, int b)
{
	return (a - dmod(a, b)) / b;
}

int main()
{
	char in[10];
	op.push_back(true);
	for (;;) {
		scanf("%s", in);
		if (in[0] >= '0' && in[0] <= '9') {
			N = atoi(in);
			break;
		}
		if (in[0] == '+') op.push_back(true);
		if (in[0] == '-') op.push_back(false);
	}
	int n_plus = 0, n_minus = 0;
	for (auto a : op) {
		if (a) ++n_plus;
		else ++n_minus;
	}
	int lo = 0, hi = 0;
	lo += n_plus - N * n_minus;
	hi += N * n_plus - n_minus;

	if (lo <= N && N <= hi) {
		puts("Possible");

		int loa = n_plus, hia = N * n_plus;
		int lob = N + n_minus, hib = N + N * n_minus;
		int target = max(loa, lob);

		vector<int> pluss, minuss;
		for (int i = 0; i < n_plus; ++i) {
			pluss.push_back(target / n_plus + (i < target % n_plus ? 1 : 0));
		}
		for (int i = 0; i < n_minus; ++i) {
			minuss.push_back(ddiv(target - N, n_minus) + (i < dmod(target - N, n_minus) ? 1 : 0));
		}

		for (int i = 0; i < op.size(); ++i) {
			if (i != 0) printf(" %c ", op[i] ? '+' : '-');
			if (op[i]) {
				printf("%d", pluss[pluss.size() - 1]);
				pluss.pop_back();
			} else {
				printf("%d", minuss[minuss.size() - 1]);
				minuss.pop_back();
			}
		}
		printf(" = %d\n", N);
	} else {
		puts("Impossible");
	}
	return 0;
}