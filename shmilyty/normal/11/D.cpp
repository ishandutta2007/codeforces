#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,m,ans,f[1<<19][19],a[19][19];
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read()-1,y=read()-1;
		a[x][y]=a[y][x]=1;
	}
	for(int i=0;i<=n;i++)
		f[1<<i][i]=1;
	for(int i=1;i<(1<<n);i++)
		for(int l=0;l<n;l++)
			if(f[i][l])
				for(int j=0;j<n;j++)
					if(a[l][j]&&((i&-i)<=(1<<j)))
					{
						if(1<<j&i)
						{
							if(1<<j==(i&-i))	
								ans+=f[i][l];
						}
						else 
							f[i|1<<j][j]+=f[i][l];
					}
	printf("%lld",(ans-m)/2);
	return 0;
}