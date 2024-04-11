#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+10;

int n,c[N],z[233],sum[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]);
	z[0] = 1;
	for(int i=1;i <= 30;i++) z[i] = z[i-1] << 1;
	if(n > 100) {puts("1");return 0;}
	int ans=1000;
	for(int i=1;i <= n;i++) sum[i] = sum[i-1]^c[i];
	for(int l=1;l < n;l++)
		for(int m=l;m < n;m++){
			for(int r=m+1;r <= n;r++)
			if((sum[r]^sum[m]) < (sum[m]^sum[l-1])) ans = min(ans,r-l-1);
		}
	printf("%d\n",ans >= 1000 ? -1 : ans);
	return 0;
}