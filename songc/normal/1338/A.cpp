#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, ans;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		ans = 0;
		int mx=-1000000000, a;
		for (int i=1; i<=N; i++){
			scanf("%d", &a);
			ans = max(ans, mx-a);
			mx = max(mx, a);
		}
		for (int i=31; i>=0; i--){
			if (ans & (1<<i)){
				printf("%d\n", i+1);
				break;
			}
		}
		if (!ans) printf("0\n");
	}
	return 0;
}