#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL ans=1;
int A[101010], P[101010], S[101010];

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	for (int i=1; i<=N; i++) P[i] = __gcd(A[i], P[i-1]);
	for (int i=N; i>0; i--) S[i] = __gcd(A[i], S[i+1]);
	for (int i=1; i<=N; i++){
		LL t = __gcd(P[i-1], S[i+1]);
		ans = ans / __gcd(ans, t) * t;
	}
	printf("%lld\n", ans);
	return 0;
}