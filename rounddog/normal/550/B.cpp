#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int a[16],f,sum,l,r,x,n,ans,m1,m2;

int main()
{
	scanf("%d%d%d%d",&n,&l,&r,&x);
	ans=0;
	for (int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	for (int i=1;i<(1<<n);i++)
	{
		int tmp=i;
		m1=0,m2=20000000,sum=0;
		for (int j=0;j<n;j++)
		{
			f=tmp%2;
			if (f){
				m1=max(m1,a[j]);
				m2=min(m2,a[j]);
				sum+=a[j];
			}
			tmp/=2;
		}
		if (m1-m2>=x&&sum<=r&&sum>=l) ans++;
	}
	printf("%d\n",ans);
	return 0;
}