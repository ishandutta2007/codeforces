#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, ans;
LL A[202020], K;

int main(){
	scanf("%d", &TC);
	while (TC--){
		LL mx=-INF, mn=INF;
		scanf("%d %lld", &N, &K);
		for (int i=1; i<=N; i++) scanf("%lld", &A[i]), mx=max(mx, A[i]), mn=min(mn, A[i]);
		K--;
		for (int i=1; i<=N; i++) A[i] = mx-A[i];
		if (K&1) for (int i=1; i<=N; i++) printf("%d ", mx-mn-A[i]);
		else for (int i=1; i<=N; i++) printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}