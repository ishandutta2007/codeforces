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
int t,n,cnt,cnt1,tot,a[200001],b[200001],f[200001],f1[200001];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n);
		cnt=cnt1=tot=0;
		for(int i=1;i<=n;i++)
		{
			int k=i;
			while(a[i+1]==a[k]&&i!=n)
				i++;
			b[++cnt]=i-k+1;
		}
		sort(b+1,b+1+cnt);
//		for(int i=1;i<=cnt;i++)
//			cout<<b[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=cnt;i++)
		{
			int k=i;
			while(b[i+1]==b[k]&&i!=cnt)
				i++;
			cnt1++;
			f[cnt1]=b[k];
			f1[cnt1]=f1[cnt1-1]+i-k+1;
			tot+=(i-k+1)*b[k];
		}
		int ans=114514114514114514;
//		cout<<tot<<endl;
		for(int i=0;i<cnt1;i++)
		{
//			cout<<f1[i]<<" "<<f[i+1]<<endl;
//			cout<<tot-(cnt-f1[i])*f[i+1]<<endl;
			ans=min(ans,tot-(cnt-f1[i])*f[i+1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}