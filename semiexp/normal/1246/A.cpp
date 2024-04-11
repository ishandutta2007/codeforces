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

int N, P;

int main()
{
	scanf("%d%d", &N, &P);

	for (int i = 1; i <= 50; ++i) {
		int hoge = N - P * i;
		if (hoge <= 0) continue;

		if (__builtin_popcount(hoge) <= i && hoge >= i) {
			printf("%d\n", i);
			return 0;
		}
	}

	puts("-1");
	return 0;
}