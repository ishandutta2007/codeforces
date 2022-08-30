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

int N, Q;
int A[101010];

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
	}

	for (; Q--;) {
		int L, R;
		scanf("%d%d", &L, &R);

		vector<int> seq;
		for (int i = L; i < R; ++i) {
			seq.push_back(abs(A[i] - A[i - 1]));
		}
		i64 ret = 0;
		i64 csum = 0;
		stack<pair<int, int> > S; // h, w
		for (int v : seq) {
			int w2 = 1;
			while (!S.empty() && S.top().first <= v) {
				w2 += S.top().second;
				csum -= (i64)S.top().first * S.top().second;
				S.pop();
			}
			csum += (i64)v * w2;
			S.push({ v, w2 });
			ret += csum;
		}

		printf("%lld\n", ret);
	}
	return 0;
}