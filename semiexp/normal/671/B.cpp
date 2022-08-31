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

int N, K;
i64 C[505050];

void pohe()
{
	i64 sum = 0;
	for (int i = N - 1; i >= 0; --i) {
		sum += C[i];
		i64 bk = (i == 0 ? 0 : C[i - 1]) * (N - i);
		if (sum - bk > K) {
			i64 rem = sum - bk - K;
			i64 rr = rem % (N - i);
			for (int j = i; j < N; ++j) {
				C[j] = C[i - 1] + rem / (N - i) + (N - j - 1 < rr ? 1 : 0);
			}
			break;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		int t;
		scanf("%d", &t);
		C[i] = t;
	}
	sort(C, C + N);

	i64 tot = 0;
	for (int i = 0; i < N; ++i) tot += C[i];
	if (tot <= K) {
		printf("%d\n", (tot % N == 0) ? 0 : 1);
		return 0;
	}

	pohe();

	for (int i = 0; i < N; ++i) C[i] = 21000000 - C[i];
	reverse(C, C + N);

	pohe();
	for (int i = 0; i < N; ++i) C[i] = 21000000 - C[i];
	reverse(C, C + N);

	printf("%d\n", (int)(C[N - 1] - C[0]));

	return 0;
}