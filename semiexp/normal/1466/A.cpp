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

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		int N, X[55];
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", X + i);
		set<int> S;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) S.insert(X[j] - X[i]);
		}
		printf("%d\n", (int)S.size());
	}
	return 0;
}