#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long i64;

int N, Q;
int V[100000], C[100000];
i64 dp[100000];
pair<i64, int> bestA, bestB;

int main()
{
	scanf("%d%d", &N, &Q);

	for(int i=0;i<N;i++) scanf("%d", V+i);
	for(int i=0;i<N;i++){
		scanf("%d", C+i); C[i]--;
	}
	
	i64 a, b;
	for(;Q--;){
		scanf("%I64d%I64d", &a, &b);
		fill(dp, dp+N, -(1LL<<60LL));

		bestA = make_pair(0LL, -1);
		bestB = make_pair(0LL, -2);

		for(int i=0;i<N;i++){
			i64 bs = -(1LL<<60LL);
			if(bestA.second != C[i]) bs = max(bs, bestA.first + V[i] * b);
			else bs = max(bs, bestB.first + V[i] * b);
			bs = max(bs, dp[C[i]] + V[i] * a);

			dp[C[i]] = max(dp[C[i]], bs);
			if(bestA.first < bs){
				if(bestA.second == C[i]) bestA.first = bs;
				else if(bestB.second == C[i]){
					swap(bestA, bestB);
					bestA.first = bs;
				}else{
					bestB = bestA;
					bestA = make_pair(bs, C[i]);
				}
			}else if(bestB.first < bs){
				if(bestA.second == C[i]) continue;
				bestB = make_pair(bs, C[i]);
			}
		}

		i64 ret = 0;
		for(int i=0;i<N;i++) ret = max(ret, dp[i]);

		printf("%I64d\n", ret);
	}

	return 0;
}