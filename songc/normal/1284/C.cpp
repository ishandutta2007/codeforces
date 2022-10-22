#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL M, ans;
LL fac[303030];

int main(){
	scanf("%d %lld", &N, &M);
	fac[0] = 1;
	for (int i=1; i<=N; i++) fac[i] = fac[i-1] * i % M;
	for (int i=1; i<=N; i++){
		LL t = N-i+1;
		t = (t*fac[i])%M;
		t = (t*fac[N-i+1])%M;
		ans = (ans+t)%M;
	}
	printf("%lld\n", ans);
	return 0;
}