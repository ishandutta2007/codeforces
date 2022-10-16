#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m;
int a[233],b[233];
long long gena[2333333],genb[2333333];
int topa,topb;
long long k;
void search(int *arr,long long *gen,int &top,long long cur,int dep)
{
	if(arr[dep]==0)
	{
		gen[++top]=cur;
		return;
	}
	search(arr,gen,top,cur,dep+1);
	while(cur<=1000000000000000000ll/arr[dep]+1)
	{
		cur*=arr[dep];
		search(arr,gen,top,cur,dep+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i&1)scanf("%d",&a[i/2+1]);
		else scanf("%d",&b[i/2]);
	}
	scanf("%lld",&k);
	search(a,gena,topa,1,1);
	search(b,genb,topb,1,1);
	sort(gena+1,gena+topa+1);
	sort(genb+1,genb+topb+1);
	long long l=1,r=1000000000000000000ll,cnt;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		cnt=0;
		int p=topb;
		//cout<<"mid = "<<mid<<endl;
		for(int i=1;i<=topa;i++)
		{
			while(p>0&&(gena[i]>mid/genb[p]+1||gena[i]*genb[p]>mid))
			{
				//cout<<p<<' '<<gena[i]<<' '<<genb[p]<<' '<<gena[i]*genb[p]<<endl;
				p--;
			}
			//if(p>0)cout<<p<<' '<<gena[i]<<' '<<genb[p]<<' '<<gena[i]*genb[p]<<endl;
			cnt+=p;
		}
		if(cnt>=k)r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}