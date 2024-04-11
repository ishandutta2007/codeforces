#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int x,y,n,cnt,ax[25],ay[25],f[1<<24],p[1<<24],d[25][25];
signed main()
{
	x=read();
	y=read();
	n=read();
	for(int i=0;i<n;i++)
	{ 
		ax[i]=read();
		ay[i]=read();
	} 
	ax[n]=x;
	ay[n]=y;
	for(int i=0;i<=n;i++)
		for(int l=0;l<=n;l++)
			d[i][l]=(ax[i]-ax[l])*(ax[i]-ax[l])+(ay[i]-ay[l])*(ay[i]-ay[l]);
	for(int i=0;i<(1<<n);i++)
		f[i]=114514114514114514;
	f[0]=0;
	for(int i=0;i<(1<<n);i++)
		if(f[i]!=114514114514114514) 
		{
			for(int l=0;l<n;l++)
				if(!(i&(1<<l)))
				{
					for(int j=0;j<n;j++)
						if(!(i&(1<<j)))
							if(f[i|(1<<l)|(1<<j)]>f[i]+d[l][n]+d[j][n]+d[l][j])
							{ 
								f[i|(1<<l)|(1<<j)]=f[i]+d[l][n]+d[j][n]+d[l][j];
								p[i|(1<<l)|(1<<j)]=i;
							}
					break;
				}	
		}
	cout<<f[(1<<n)-1]<<endl<<0<<" ";
	cnt=(1<<n)-1;
	while(cnt)
	{
		int k=cnt-p[cnt];
		for(int i=0;i<n;i++)
			if(k&(1<<i))
				cout<<i+1<<" ";
		cout<<0<<" ";
		cnt=p[cnt];
	}
	return 0;
}