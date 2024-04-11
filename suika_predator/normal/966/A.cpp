#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,cl,ce,v,q,x,y,xx,yy;
int l[233333],e[233333];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=1;i<=cl;i++)
	{
		scanf("%d",&l[i]);
	}
	l[cl+1]=m+1;
	for(int i=1;i<=ce;i++)
	{
		scanf("%d",&e[i]);
	}
	e[ce+1]=m+1;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		if(x==xx)printf("%d\n",abs(y-yy));
		else
		{
			int ans=0x3f3f3f3f;
			int ll=0,rr=cl+1;
			while(ll<rr)//left ladder
			{
				int mid=(ll+rr+1)>>1;
				if(l[mid]<y)ll=mid;
				else rr=mid-1;
			}
			if(l[ll]<=m&&l[ll]>=1)ans=min(ans,abs(l[ll]-y)+abs(l[ll]-yy)+abs(x-xx));
			
			ll=0,rr=cl+1;
			while(ll<rr)//right ladder
			{
				int mid=(ll+rr)>>1;
				if(l[mid]<y)ll=mid+1;
				else rr=mid;
			}
			if(l[ll]<=m&&l[ll]>=1)ans=min(ans,abs(l[ll]-y)+abs(l[ll]-yy)+abs(x-xx));
			
			ll=0,rr=ce+1;
			while(ll<rr)//left elevator
			{
				int mid=(ll+rr+1)>>1;
				if(e[mid]<y)ll=mid;
				else rr=mid-1;
			}
			if(e[ll]<=m&&e[ll]>=1)ans=min(ans,abs(e[ll]-y)+abs(e[ll]-yy)+(abs(x-xx)+(v-1))/v);
			
			ll=0,rr=ce+1;
			while(ll<rr)//right elevator
			{
				int mid=(ll+rr)>>1;
				if(e[mid]<y)ll=mid+1;
				else rr=mid;
			}
			if(e[ll]<=m&&e[ll]>=1)ans=min(ans,abs(e[ll]-y)+abs(e[ll]-yy)+(abs(x-xx)+(v-1))/v);
			
			printf("%d\n",ans);
		}
	}
	return 0;
}