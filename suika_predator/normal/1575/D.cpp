#include<bits/stdc++.h>
using namespace std;
int n,X,ans;
char s[11];
bool check()
{
	if(n==1)return s[1]=='0';
	if(n>1 and s[1]=='0')return false;
	if(s[n]=='0')
	{
		return s[n-1]=='5' or s[n-1]=='0';
	}
	else if(s[n]=='5')
	{
		return s[n-1]=='2' or s[n-1]=='7';
	}
	return false;
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		if(check())
			ans+=1;
		return;
	}
	if(s[pos]=='X')
	{
		s[pos]='0'+X;
		dfs(pos+1);
		s[pos]='X';
	}
	else if(isdigit(s[pos]))
	{
		dfs(pos+1);
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			s[pos]='0'+i;
			dfs(pos+1);
		}
		s[pos]='_';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>(s+1);
	n=strlen(s+1);
	int hasX=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='X')hasX=1;
	}
	if(hasX)
	{
		for(X=0;X<=9;X++)
		{
			dfs(1);
		}
	}
	else
	{
		dfs(1);
	}
	cout<<ans<<endl;
	return 0;
}