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

int TC;
int N, A[110], B[110], C[110];
int ans[110];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		for (int i=1; i<=N; i++) scanf("%d", &B[i]);
		for (int i=1; i<=N; i++) scanf("%d", &C[i]);
		ans[1] = A[1];
		for (int i=2; i<N; i++){
			if (A[i] == ans[i-1]) ans[i] = B[i];
			else ans[i] = A[i];
		}
		if (ans[1] != A[N] && ans[N-1] != A[N]) ans[N] = A[N];
		if (ans[1] != B[N] && ans[N-1] != B[N]) ans[N] = B[N];
		if (ans[1] != C[N] && ans[N-1] != C[N]) ans[N] = C[N];
		for (int i=1; i<=N; i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}