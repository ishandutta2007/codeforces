#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
int main() {
	scanf("%d",&t);
	while(t--){
		LL n,k; scanf("%lld%lld",&n,&k);
		k=k*k;
		if(k%2==n%2 && k<=n) printf("YES\n");
		else printf("NO\n");
	}
}