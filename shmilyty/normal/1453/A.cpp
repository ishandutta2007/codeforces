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
int t,n,m,a[101],b[101]; 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=1;i<=m;i++)
			b[i]=read();
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
				if(a[i]==b[l])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}