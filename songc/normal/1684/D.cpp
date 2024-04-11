#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K, Q;
LL ans;
int A[202020];

int main(){
	scanf("%d", &Q);
	while (Q--){
		scanf("%d %d", &N, &K);
		ans = 0;
		for (int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			ans += A[i];
			A[i] -= (N-i);
		}
		sort(A+1, A+N+1);
		for (int i=N-K+1; i<=N; i++) ans -= A[i];
		ans -= K*(K-1ll)/2;
		printf("%lld\n", ans);
	}
	return 0;
}