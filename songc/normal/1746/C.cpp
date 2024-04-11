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
pii P[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		int sum=0;
		for (int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			P[i] = pii(A[i-1]-A[i], i);
		}
		sort(P+1, P+N+1);
		for (int i=1; i<=N; i++) printf("%d ", P[i].se);
		printf("\n");
	}
	return 0;
}