#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, TC;
int A[202020];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		LL mn=INF, mx=-1, mxi=0;
		for (int i=1; i<=N; i++){
			LL sum = 0;
			for (int j=1; j<=M; j++){
				LL a;
				scanf("%lld", &a);
				sum += a*j;
			}
			if (mx < sum) mx = sum, mxi = i;
			mn = min(mn, sum);
		}
		printf("%d %lld\n", mxi, mx - mn);
	}
	return 0;
}