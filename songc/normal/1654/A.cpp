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

int TC, N, M;
int mx, sm;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		mx=sm=0;
		for (int i=1; i<=N; i++){
			int a;
			scanf("%d", &a);
			if (mx < a) sm = mx, mx = a;
			else if (sm < a) sm = a;
		}
		printf("%d\n", mx+sm);
	}
	return 0;
}