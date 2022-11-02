#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n,m,k,c[4000],f[4000]; 

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i <= n;i++)
			scanf("%d",&c[i]);
		int l = n-m+1;
		for(int i=1;i+l-1 <= n;i++)
			f[i] = max(c[i],c[i+l-1]);
		int ll = max(n-k-l+1,1),ans = 0;
		for(int i=1;i+ll-1 <= n+1-l;i++){
			int minn = 1e9+1;
			for(int j=0;j < ll;j++)
				minn = min(minn,f[i+j]);
			ans = max(ans,minn);
		}
		printf("%d\n",ans);
	}
	return 0;
}