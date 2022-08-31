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

int T;
vector<int> miner, dia;

int myabs(int x) {
	return max(x, -x);
}

double yosupot(i64 x, i64 y) {
	return sqrt(x * x + y * y);
}

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		int N;
		scanf("%d", &N);
		miner.clear();
		dia.clear();
		for (int i = 0; i < 2 * N; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == 0) miner.push_back(myabs(y));
			else dia.push_back(myabs(x));
		}
		sort(miner.begin(), miner.end());
		sort(dia.begin(), dia.end());

		double ret = 0;
		for (int i = 0; i < N; ++i) {
			ret += yosupot(miner[i], dia[i]);
		}
		printf("%.12f\n", ret);
	}
	return 0;
}