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

int main()
{
	int p, k;
	scanf("%d%d", &p, &k);

	if (k == 0) {
		i64 ret = 1;
		for (int i = 1; i < p; ++i) ret = ret * p % MOD;
		cout << ret << endl;
		return 0;
	} else if (k == 1) {
		i64 ret = 1;
		for (int i = 0; i < p; ++i) ret = ret * p % MOD;
		cout << ret << endl;
		return 0;
	}

	i64 v = 1;
	int c = 0;
	do {
		++c;
		v = v * k % p;
	} while (v != 1);
	fprintf(stderr, "%d\n", c);

	i64 ret = 1;
	for (int i = 0; i < (p - 1) / c; ++i) ret = ret * p % MOD;
	cout << ret << endl;
	return 0;
}