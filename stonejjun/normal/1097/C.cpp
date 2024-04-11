#include<bits/stdc++.h>
using namespace std;
char aa[5050505];

struct gg
{
	int l,r,hap;
};
gg arr[5050505];
int dap[5050505];

bool sf(gg a, gg b)
{
	return a.hap<b.hap;
}

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; // 
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&aa);
		for(j=0;j<strlen(aa);j++)
		{
			if(aa[j]=='(') arr[i].l++;
			else if(aa[j]==')'&&arr[i].l!=0) arr[i].l--;
			else if(aa[j]==')'&&arr[i].l==0) arr[i].r++;
		}
//		printf("%d %d\n",arr[i].l,arr[i].r);
	}
	
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		if(arr[i].l==0||arr[i].r==0)
		{
			cnt++;
			dap[cnt]=arr[i].l-arr[i].r;
		}
	}
	sort(dap+1,dap+1+cnt);
//	for(i=1;i<=cnt;i++)
//	{
//		printf("%d\n",dap[i]);
//	}
	
	int ll=1,rr=cnt;
	while(ll<rr)
	{
		if(dap[ll]+dap[rr]==0)
		{
			ans++;
			ll++;
			rr--;
		}
		if(dap[ll]+dap[rr]>0)
		{
			rr--;
		}
		if(dap[ll]+dap[rr]<0)
		{
			ll++;
		}
	}
	
	
	printf("%d",ans);
	
	
}