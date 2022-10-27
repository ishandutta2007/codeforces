#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,m;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		LL tot = 1LL * n * (n+1) / 2;
		int A = n - m;
		int B = m + 1;
		LL L1 = A / B, C1 = B - A % B;
		LL L2 = A / B + 1, C2 = A % B;
		tot -= C1 * (L1 * (L1 + 1) / 2);
		tot -= C2 * (L2 * (L2 + 1) / 2);
		printf("%lld\n", tot);
	}
}
/*
n - m
m + 1


7 3
*/