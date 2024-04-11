#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
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
int n,ans,top,len1,len2,a[10001],L[10001],R[10001],pre[10001],nxt[10001],stk[10001],pos1[10002],pos2[10002]; 
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		L[i]=max(L[i],L[i-1]);
		int minn=a[i];
		for(int l=i;l<=n;l++)
		{
			minn=min(minn,a[l]);
			L[l]=max(L[l],minn*(l-i+1));
		}
	}
	for(int i=n;i;i--)
	{
		if(i!=n)
			R[i]=max(R[i],R[i+1]);
		int minn=a[i];
		for(int l=i;l;l--)
		{
			minn=min(minn,a[l]);
			R[l]=max(R[l],minn*(i-l+1));
		}
	}
	for(int i=0;i<n;i++)
		ans=max(ans,L[i]+R[i+1]);
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]]>=a[i])
			top--;
		pre[i]=stk[top]+1;
		stk[++top]=i;
	}
	stk[0]=n+1;
	top=0;
	for(int i=n;i;i--)
	{
		while(top&&a[stk[top]]>=a[i])
			top--;
		nxt[i]=stk[top]-1;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)
		for(int l=pre[i];l<=nxt[i];l++)
			if(pre[l]>=pre[i]&&nxt[l]<=nxt[i])
				ans=max(ans,a[i]*(nxt[i]-pre[i]+1)+(a[l]-a[i])*(nxt[l]-pre[l]+1));
	for(int i=1;i<=n;i++)
		if(pre[i]!=1&&nxt[i]!=n)
		{
			int minn=INF;
			len1=len2=0;
			for(int l=pre[i]-1;l;l--)
			{
				minn=min(minn,a[l]);
				if(minn==a[l])
					pos1[++len1]=l;
			}
			minn=INF;
			for(int l=nxt[i]+1;l<=n;l++)
			{
				minn=min(minn,a[l]);
				if(minn==a[l])
					pos2[++len2]=l;
			}
			int cnt=len2,val=0;
			pos1[len1+1]=0;
			pos2[len2+1]=n+1;
			for(int l=1;l<=len1;l++)
			{
				while(cnt&&a[pos1[l]]+a[pos2[cnt]]<=a[i])
				{
					val=max(val,a[pos2[cnt]]*(pos2[cnt+1]-pre[i]));
					cnt--;
				}
				ans=max(ans,a[pos1[l]]*(nxt[i]-pos1[l+1])+val);
			}
			cnt=len2;
			for(int l=1;l<=len1;l++)
			{
				while(cnt&&a[pos1[l]]+a[pos2[cnt]]<a[i])
					cnt--;
				if(cnt)
					ans=max(ans,a[pos1[l]]*(nxt[i]-pos1[l+1])+(a[i]-a[pos1[l]])*(pos2[cnt+1]-pre[i]));
			}
			cnt=len1;
			for(int l=1;l<=len2;l++)
			{
				while(cnt&&a[pos1[cnt]]+a[pos2[l]]<a[i])
					cnt--;
				if(cnt)
					ans=max(ans,a[pos2[l]]*(pos2[l+1]-pre[i])+(a[i]-a[pos2[l]])*(nxt[i]-pos1[cnt+1]));
			}
		}
	cout<<ans;
	return 0;
}