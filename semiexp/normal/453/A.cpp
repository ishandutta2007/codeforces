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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

double mpow(double x, int p)
{
	if (p == 0) return 1.0;
	if (p == 1) return x;
	double tmp = mpow(x, p / 2);
	tmp *= tmp;
	if (p % 2 == 1) tmp *= x;

	return tmp;
}

int main()
{
	int M, N;
	scanf("%d%d", &M, &N);

	double ret = M;
	for (int i = 1; i <= M - 1; i++) {
		ret -= mpow((double)i / M, N);
	}
	printf("%.8f\n", ret);
	return 0;
}