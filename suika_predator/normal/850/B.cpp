#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,y,k;
long long minn=0x3f3f3f3f3f3f3f3fll,sum,last,ss[2000010];
int a[2000010];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	k=x/y;
	int tmp;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&tmp);
		++a[tmp];
	}
	for(int i=1;i<=2000000;++i)a[i]+=a[i-1];
	for(int i=1;i<=2000000;++i)ss[i]=a[i]+ss[i-1];
	for(int i=2;i<=2000000;++i)
	{
		sum=last=0;
		for(int j=i;j<=2000000;j+=i)
		{
			if(j-k>last)
			{
				//a=j-k-1,b=last
				sum+=(long long)(a[j-k-1]-a[last])*x;
				//a=j-1,b=j-k-1
				sum+=(ss[j-1]-ss[j-k-1]-(long long)a[j-k-1]*(k))*y;
			}
			else
			{
				//a=j-1,b=last
				sum+=(ss[j-1]-ss[last]-(long long)a[last]*(j-last-1))*y;
			}
			last=j;
		}
		if(sum<minn)minn=sum;//cout<<(minn=sum)<<' '<<i<<endl;//
		//cout<<i<<' '<<sum<<' '<<k<<endl;
	}
	printf("%I64d\n",minn);
	return 0;
}