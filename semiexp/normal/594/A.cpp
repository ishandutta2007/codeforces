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

int N, X[202020];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", X + i);
	sort(X, X + N);

	int ret = 2100000000;
	for (int i = 0; i < N / 2; ++i) {
		ret = min(ret, X[i + N / 2] - X[i]);
	}
	printf("%d\n", ret);
	return 0;
}