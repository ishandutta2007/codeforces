#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M;
LL sum;
int A[101010], ans[101010];

int main(){
	scanf("%d %d", &M, &N);
	for (int i=1; i<=N; i++){
		scanf("%d", &A[i]);
		sum += A[i];
	}
	if (sum < M){
		puts("-1");
		return 0;
	}
	ans[N] = M-A[N]+1;
	for (int i=N-1; i>=1; i--) ans[i] = min(ans[i+1]-1, M-A[i]+1);
	if (ans[1] < 1){
		puts("-1");
		return 0;
	}
	sum=1;
	for (int i=1; i<=N; i++){
		printf("%lld ", min(sum, (LL)ans[i]));
		sum += A[i];
	}
	puts("");
	return 0;
}