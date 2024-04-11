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
int n,ans,f[4001][4001],a[4001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		for(int l=0,p=0;l<i;l++)
		{
			f[l][i]=f[p][l]+1;
			ans=max(ans,f[l][i]);
			if(a[i]==a[l])
				p=l;
		} 
	cout<<ans;
	return 0;
}