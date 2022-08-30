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

int N, A[252525];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N * N; ++i) scanf("%d", A + i);

	multiset<int> S;
	for (int i = 0; i < N *N; ++i) S.insert(A[i]);

	vector<int> ans;

	for (int i = 0; i < N; ++i) {
		int c = *--S.end();
		S.erase(S.lower_bound(c));
		for (int d : ans) {
			int g = gcd(c, d);
			S.erase(S.lower_bound(g));
			S.erase(S.lower_bound(g));
		}
		ans.push_back(c);
	}
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
	}
	return 0;
}