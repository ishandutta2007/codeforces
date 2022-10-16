#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n[4],c[4][100001];
int calc(int x,int y,int z)
{
	return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&n[1],&n[2],&n[3]);
		memset(c,0,sizeof(c));
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=3;i++)
		{
			for(int l=1;l<=n[i];l++)
				scanf("%lld",&c[i][l]);
			sort(c[i]+1,c[i]+1+n[i]);
		}	 
		for(int i=1;i<=3;i++)
			for(int l=1;l<=3;l++)
				for(int k=1;k<=3;k++)
					if(i*l*k==6)
						for(int j=1;j<=n[l];j++)
						{
							int a=lower_bound(c[i]+1,c[i]+1+n[i],c[l][j])-c[i];
							int b=upper_bound(c[k]+1,c[k]+1+n[k],c[l][j])-c[k];
							if(a!=n[i]+1&&b!=1)
							{
								b--;
								ans=min(ans,calc(c[l][j],c[i][a],c[k][b]));
							}
						}
		cout<<ans<<endl;
	}
	return 0;
}