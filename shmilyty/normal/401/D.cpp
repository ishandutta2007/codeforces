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
int n,m,cnt,a[19],vis[19],f[1<<18][101][2];
signed main()
{
	n=read();
	m=read();
	while(n)
	{
		a[cnt++]=n%10;
		n/=10;
	}
	f[0][0][0]=1;
	for(int i=0;i<(1<<cnt);i++)
	{
		memset(vis,0,sizeof(vis));
		for(int l=0;l<cnt;l++)
		{
			if(vis[a[l]]||i&(1<<l))
				continue;
			vis[a[l]]=1;
			for(int j=0;j<m;j++)
				if(a[l])
					f[i+(1<<l)][(j*10+a[l])%m][1]+=f[i][j][0]+f[i][j][1];
				else
					f[i+(1<<l)][j*10%m][1]+=f[i][j][1];
		}
	}
	cout<<f[(1<<cnt)-1][0][1];
	return 0;
}