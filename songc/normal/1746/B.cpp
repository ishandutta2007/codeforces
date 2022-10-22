#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60);
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, K;
int A[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		int sum=0;
		for (int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			sum += A[i];
			A[i] += A[i-1];
		}
		int ans = MOD;
		for (int i=0; i<=N; i++) ans = min(ans, A[i] + max(0, (N-i)-sum));
		printf("%d\n", ans);
	}
	return 0;
}