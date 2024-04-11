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

int N, TC;
int A[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		sort(A+1, A+N+1);
		LL ans=A[N], sum=0;
		for (int i=1; i<=N; i++){
			ans -= A[i]*(i-1ll) - sum;
			sum += A[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}