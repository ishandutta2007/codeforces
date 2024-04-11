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

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &K);
		int x=0, ans=0;
		for (int i=1; i<=N; i++){
			scanf("%d", &x);
			if (x) ans = 1;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}