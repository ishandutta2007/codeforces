#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int T,n,a[N],mx,mn,k,ans;
int main() 
{
	scanf("%d",&T);
	while(T--) 
	{
		scanf("%d",&n);
		mx=-1;
		
		mn=2e9;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=-1 and (a[i-1]==-1 or a[i+1]==-1))
			{
				mx=max(mx,a[i]);
				mn=min(mn,a[i]);
			} 
		}
		k=(mx+mn)>>1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1)a[i]=k;
			if(i!=1)ans=max(ans,abs(a[i]-a[i-1]));
		}
		printf("%d %d\n",ans,k);
		ans=k=0;
	}
	return 0; 
}