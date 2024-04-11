#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K;
LL ans=1;
pii A[202020];

int main(){
	scanf("%d %d", &N, &K);
	printf("%lld ", ((LL)N*(N+1)/2)-((LL)(N-K)*(N-K+1)/2));
	for (int i=1; i<=N; i++){
		scanf("%d", &A[i].first);
		A[i].second = i;
	}
	sort(A+1, A+N+1, [&](pii a, pii b){return a.fi > b.fi;});
	sort(A+1, A+K+1, [&](pii a, pii b){return a.se < b.se;});
	for (int i=2; i<=K; i++) ans = ans*(A[i].se-A[i-1].se)%998244353;
		printf("%lld\n", ans);
	return 0;
}