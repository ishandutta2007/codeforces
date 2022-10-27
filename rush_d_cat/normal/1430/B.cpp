#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k,a[N];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		LL ans=0;
		for(int i=n;i>=n-k;i--)ans+=a[i];
		printf("%lld\n", ans);
	}	
}