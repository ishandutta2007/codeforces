#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100011],buc[1000011],q[100011][2],qn;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		n<<=1;
		for(int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n);
		bool ok=0;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
				buc[a[j]]=0;
			for(int j=1;j<=n;j++)
				buc[a[j]]++;
			qn=0;
			int x=a[i]+a[n];
			bool flg=1;
			for(int j=n;j;j--)
			{
				if(!buc[a[j]])
					continue;
				buc[a[j]]--;
				if(!buc[x-a[j]])
				{
					flg=0;
					break;
				}
				qn++;
				q[qn][0]=a[j];
				q[qn][1]=x-a[j];
				buc[x-a[j]]--;
				x=a[j];
			}
			if(flg&&qn==n/2)
			{
				printf("YES\n%lld\n",a[i]+a[n]);
				for(int i=1;i<=qn;i++)
					printf("%lld %lld\n",q[i][0],q[i][1]);
				ok=1;
				break;
			}
		}
		if(!ok)
			printf("NO\n");
	}
	return 0;
}//114514