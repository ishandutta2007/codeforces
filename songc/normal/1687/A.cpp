#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, K;
LL A[202020], ans;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &K);
		for (int i=1; i<=N; i++) scanf("%lld", &A[i]), A[i]+=A[i-1];
		if (K > N){
			printf("%lld\n", A[N]+(K-1ll)*N-(N-1ll)*N/2);
		}
		else{
			LL mx=0;
			for (int i=0; i+K<=N; i++) mx = max(mx, A[i+K]-A[i]);
			printf("%lld\n", mx+(K-1ll)*K/2);
		}
	}
	return 0;
}