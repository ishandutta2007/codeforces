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

int TC, N, M, Q;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		int mn=MOD, mx=-MOD, a=0, b=0;
		for (int i=1; i<=N; i++){
			int x;
			scanf("%d", &x);
			if (mn > x) mn = x, a=i;
			if (mx < x) mx = x, b=i;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}