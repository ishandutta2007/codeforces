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
	if(flag)
		return x;
	else
		return ~(x-1);
}
int match[701],f[701][701][3][3];
const int mod=1000000007;
int dfs(int l,int r,int x,int y)
{
	if(f[l][r][x][y]!=-1)
		return f[l][r][x][y];
	else 
		if(r-l==1) 
			return f[l][r][x][y]=(x>0)!=(y>0);
	f[l][r][x][y]=0;
	if(match[l]==r)
	{
		if(!x&&!y||x&&y)
			return f[l][r][x][y];
		if(x==0)
		{
			return f[l][r][x][y]=(dfs(l+1,r-1,1,0)+dfs(l+1,r-1,2,0)+
			dfs(l+1,r-1,0,3-y)+dfs(l+1,r-1,1,3-y)+
			dfs(l+1,r-1,2,3-y)+dfs(l+1,r-1,0,0))%mod;
		}
		return f[l][r][x][y]=(dfs(l+1,r-1,0,1)+dfs(l+1,r-1,0,2)+
		dfs(l+1,r-1,3-x,0)+dfs(l+1,r-1,3-x,1)+
		dfs(l+1,r-1,3-x,2)+dfs(l+1,r-1,0,0))%mod;
	}
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			f[l][r][i][j]=0;
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			for(int k=0;k<=2;k++)
				for(int p=0;p<=2;p++)
				{
					if(j&&k&&(j==k))
						continue;
					(f[l][r][i][p]+=dfs(l,match[l],i,j)*
					dfs(match[l]+1,r,k,p))%=mod;
				}
	return f[l][r][x][y];		
}
signed main()
{
	memset(f,-1,sizeof(f));
	string s;
	cin>>s;
	stack<int> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			st.push(i+1);
		else
		{
			match[st.top()]=i+1;
			st.pop();
		}
	}
	int ans=0;
	for(int i=0;i<=2;i++)
		for(int l=0;l<=2;l++)
			(ans+=dfs(1,s.size(),i,l))%=mod;
	cout<<ans;
	return 0;
}