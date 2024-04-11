#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,a[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) scanf("%d",&a[i]);
		printf("%d\n",n-1);
		if(n == 1) continue;
		int las = 1;
		for(int i=1;i < n-1;i++) printf("%d %d %d %d\n",i,i+1,las = 1000000000+i-1,a[i+1] = min(a[i],a[i+1])); 
		a[n] = min(a[n-1],a[n]);
		for(int i=1;;i++) if(__gcd(1000000000+i-1,a[n]) == 1 && __gcd(1000000000+i-1,las) == 1){
			printf("%d %d %d %d\n",n-1,n,1000000000+i-1,a[n]); break;
		}
	}
}