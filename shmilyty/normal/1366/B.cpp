#include<bits/stdc++.h>
using namespace std;
int t,n,x,m,L,R,k,l[101],r[101];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&m);
		k=L=R=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<=m;i++)
			if(l[i]<=x&&x<=r[i])
			{
				k=i;
				L=l[i];
				R=r[i];
				break;
			}
		for(int i=k+1;i<=m;i++)
		{
			if(r[i]<L)
				continue;
			if(l[i]>R)
				continue;
			L=min(l[i],L);
			R=max(r[i],R);
		}
		cout<<R-L+1<<endl;
	}
	return 0;
}