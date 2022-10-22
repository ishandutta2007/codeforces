#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
int A[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		int ans = A[N]-A[1];
		int mx = 0, mn = MOD;
		for (int i=2; i<=N; i++) ans = max(ans, A[i-1]-A[i]);
		for (int i=2; i<=N; i++) mx = max(mx, A[i]);
		for (int i=1; i<N; i++) mn = min(mn, A[i]);
		printf("%d\n", max(ans, max(A[N]-mn, mx-A[1])));
	}
	return 0;
}