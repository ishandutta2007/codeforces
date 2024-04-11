#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<cstring>
#include<algorithm>

#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>

#define Rep(i, a, b) for (int i(a); i <= (b); ++i)

using namespace std;

typedef long long LL;

const int MAXN = 5023;


int N, X[MAXN], Y[MAXN], Z[MAXN];

inline double dist(int i, int j) {
	LL a = X[i] - X[j]; a = a * a;
	LL b = Y[i] - Y[j]; b = b * b;
	LL c = Z[i] - Z[j]; c = c * c;
	return sqrt(a + b + c);
}

int main() {
	scanf("%d", &N);
	Rep(i, 1, N) {
		scanf("%d %d %d", X + i, Y + i, Z + i);
	}
	double ans = 1e100;
	Rep(i, 2, N) Rep(j, i + 1, N) {
		ans = min(ans, dist(i, j) + dist(1, i) + dist(1, j));
	}
	printf("%.8f\n", ans * 0.5);
	return 0;
}