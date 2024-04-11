#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3000 + 10;
int t,n,a[N];
int b1[N],b2[N]; LL sum=0;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		LL res=0;
		for(int l=1;l<=n-3;l++){
			memset(b1,0,sizeof(b1));
			memset(b2,0,sizeof(b2));

			for(int i=l+3;i<=n;i++) b2[ a[i] ] ++;
			b1[ a[l+1] ] ++;
			sum = b2[ a[l+1] ];
			if (a[l] == a[l+2]) res += sum;
			for(int i=l+2;i<n;i++) {
				// b1: add a[i]
				// b2: del a[i+1]
				b1[a[i]] ++; sum += b2[a[i]]; 
				b2[a[i+1]]--; sum -= b1[a[i+1]];
				if (a[l] == a[i+1]) res += sum;
				//printf("%d %d %lld\n", l, i, sum);
			}
		}
		printf("%lld\n", res);
	}
}