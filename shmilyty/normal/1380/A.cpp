#include<bits/stdc++.h>
using namespace std;
int t,n,a[1001],maxx[1001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool out=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int l=i-1;l<=n;l++)
				maxx[l]=0;
			maxx[i]=i;
			for(int l=i+1;l<=n;l++)
				if(a[l]>=a[maxx[l-1]])
					maxx[l]=l;
				else
				{
					maxx[l]=maxx[l-1];
					if(maxx[l]!=i)
					{
						puts("YES");
						cout<<i<<" "<<maxx[l]<<" "<<l<<endl;
						out=0;
						break;
					}
				}
			if(!out)
				break;
		}
		if(out)
			puts("NO");	
	}
	return 0;
}