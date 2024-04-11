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

int N, R[1010], C[1010];

int fro(int *a, int p)
{
	for (int i = 0; i < N; ++i) {
		if (a[i] == p) return i;
	}
	return -1;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", R + i);
	for (int i = 0; i < N; ++i) scanf("%d", C + i);
	for (int i = 0; i < N; ++i) {
		--R[i]; --C[i];
	}
	vector<int> X, Y, Z, W;
	for (int i = 0; i < N; ++i) {
		int a = fro(R, i);
		int b = fro(C, i);
		if (a == i && b == i) continue;
		X.push_back(i);
		Y.push_back(b);
		Z.push_back(a);
		W.push_back(i);
		R[a] = R[i];
		C[b] = C[i];
		R[i] = i;
		C[i] = i;
	}
	printf("%d\n", X.size());
	for (int i = 0; i < X.size(); ++i) {
		printf("%d %d %d %d\n", X[i] + 1, Y[i] + 1, Z[i] + 1, W[i] + 1);
	}
	
	return 0;
}