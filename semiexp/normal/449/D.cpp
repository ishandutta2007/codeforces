#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)
typedef long long i64;

int N;
int A[1000000];
int cnt[1 << 20];
i64 pows[1100000];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		scanf("%d", A+i);
	}
	pows[0] = 1;
	for(int i=1;i<=N;i++) pows[i] = (pows[i-1] * 2) % MOD;

	for(int i=0;i<(1<<20);i++) cnt[i] = 0;
	for(int i=0;i<N;i++) {
		cnt[1048575 ^ A[i]]++;
	}
	for(int i=0;i<20;i++) {
		for(int j=0;j<(1<<20);j++) {
			if(0 == (j & (1<<i))) {
				cnt[j | (1<<i)] += cnt[j];
			}
		}
	}
	i64 ret = 0;
	for(int i=0;i<(1<<20);i++) {
		int mask = 20 % 2;
		for(int j=0;j<20;j++) if(i & (1<<j)) mask ^= 1;

		if(mask == 0) ret = (ret + pows[cnt[i]]) % MOD;
		else ret = (ret + MOD - pows[cnt[i]]) % MOD;
	}
	printf("%d\n", (int) ret);

	return 0;
}