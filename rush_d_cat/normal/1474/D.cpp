#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
LL a[N],x[N];

LL premin[N];
LL sufmin[N];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		
		x[1]=a[1];
		for(int i=2;i<=n;i++) x[i]=a[i]-x[i-1];

		premin[1] = x[1];
		for(int i=2;i<=n;i++) premin[i]=min(premin[i-1],x[i]);

		sufmin[n] = x[n]; sufmin[n-1] = x[n-1];
		for(int i=n-2;i>=1;i--) sufmin[i]=min(sufmin[i+2],x[i]);
		
		if(x[n]==0 && premin[n]>=0) printf("YES\n");
		else {
			bool ac=0;
			for(int i=1;i<n;i++) {
				// swap(a[i],a[i+1])
				bool ok=1;
				if(premin[i-1] < 0) ok=0;
				if(a[i+1]-x[i-1] < 0) ok=0;
				// [i+1,n]

				int d1=-2*(a[i+1]-a[i]);
				if(sufmin[i+1] + d1 < 0) ok=0;
				int d2=2*(a[i+1]-a[i]);
				if(i+2<=n && sufmin[i+2] + d2 < 0) ok=0;

				int tmp=x[n];
				if(n%2==(i+1)%2) tmp+=d1;
				if(n%2==(i+2)%2) tmp+=d2;
				if(tmp!=0) ok=0;

				if(ok)ac=1;
			}
			printf("%s\n", ac?"YES":"NO");
		}
	}
}