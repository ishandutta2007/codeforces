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

int N;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		if (i == 1) {
			printf("%d\n", 2);
		} else {
			i64 k = i;
			i64 ans = k * (k + 1) * (k + 1) - (k - 1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}