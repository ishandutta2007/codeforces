#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,ans,S[5001],tmp[5001]; 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=n;i++)
			S[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(tmp[i]==0&&S[i]==1)
				continue;
			ans+=max(0ll,S[i]-tmp[i]-1);
			int l=i+2;
			int r=min(n,i+S[i]);
			for(l;l<=r;l++)
				tmp[l]++;
			tmp[min(n,i+1)]+=max(0ll,tmp[i]-(S[i]-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}