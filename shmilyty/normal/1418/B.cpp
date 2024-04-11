#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int t,n,cnt,a[101],loc[101],b[101];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&loc[i]);
			if(loc[i]==0)
				b[++cnt]=a[i];
		}
		sort(b+1,b+1+cnt,cmp);
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(loc[i]==0)
			{
				a[i]=b[cnt];
				cnt++;
			}
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}