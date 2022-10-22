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

int N, X, ans, TC;
int A[202020];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &X);
		ans = 0;
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		int mn = A[1], mx = A[1];
		for (int i=2; i<=N; i++){
			mn = min(mn, A[i]);
			mx = max(mx, A[i]);
			if (mx - mn > 2*X){
				mn = mx = A[i];
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}