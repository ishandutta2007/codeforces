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
char p[100001];
int n,ans,an,sum,h[100001],g[100001],v[100001],f[100001][20],s[100001][30];
int get(int x,int y)
{
	return h[y]-h[x-1]*g[y-x+1];
}
int cal(int x,int y,int z)
{
	return s[y][z]-s[x-1][z];
}
void dfs(int l,int r,int hash)
{
	int len=r-l+1,A=r+1;
	an+=len*len;
	if(A+len<=n&&hash==get(A+1,A+len)&&cal(A+1,A+len,p[A]-'a')==0)
		dfs(l,A+len,hash*g[len+1]+get(A,A+len));
	A=l-1;
	if(A-len>0&&get(A-len,A-1)==hash&&cal(A-len,A-1,p[A]-'a')==0)
		dfs(A-len,r,get(A-len,A)*g[len]+hash);
}
void pre()
{
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		h[i]=h[i-1]*10007+p[i];
		g[i]=g[i-1]*10007;
	}
	for(int i=1;i<=n;i++)
	{
		memcpy(s[i],s[i-1],sizeof(s[i]));
		s[i][p[i]-'a']++;
	}
	for(int i=1,k=0;i<=n;k++,i=i*2+1)
		for(int l=1;l<=n-i+1;l++)
		{
			int r=i+l-1,A=l+i/2;
			if(!k||get(l,A-1)==get(A+1,r)&&cal(l,r,p[A]-'a')==1&&f[l][k-1]&&f[A+1][k-1])
			{
				int s=i*i;
				sum+=s;
				v[l]+=s;
				v[r+1]-=s;
				f[l][k]=1;
			}
		}
	for(int i=1;i<=n;i++)
		v[i]+=v[i-1];
}
void solve()
{
	ans=sum;
	for(int i=1;i<=n;i++)
	{
		int res=sum-v[i];
		for(int u=0;u<25;u++)
		{
			an=res;
			for(int k=0,j=0;;j=j*2+1,k++)
			{
				int l=i-j,r=i+j;
				if(l<1||r>n)
					break;
				if(!k||get(l,i-1)==get(i+1,r)&&cal(l,i-1,u)+cal(i+1,r,u)==0&&f[l][k-1]&&f[i+1][k-1])
					dfs(l,r,get(l,i-1)*g[j+1]+(u+'a')*g[j]+get(i+1,r));
				else
					break;
			}
			ans=max(ans,an);
		}
	}
}
signed main()
{
	scanf("%s",p+1);
	n=strlen(p+1);
	pre();
	solve();
	cout<<ans;
	return 0;
}