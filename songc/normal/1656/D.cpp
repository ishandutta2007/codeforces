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

int TC;
LL N;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%lld", &N);
		LL x = 2;
		while (N%2==0) N/=2, x*=2;
		if (N == 1) printf("-1\n");
		else printf("%lld\n", min(x, N));
	}
	return 0;
}