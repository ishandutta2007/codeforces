#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000000001LL
int c[110][110],a[11100],n,m;ll p;
char s[210];ll f[210][210];
inline void upd(ll &a,ll b)
{
	if(b==INF){a=INF;return;}
	if(a>=INF-b){a=INF;return;}
	a+=b;
}
ll ff()
{
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=0;i<n+m-1;i++)
	{
		bool f0,f1;
		if(!s[i])f0=f1=1;
		if(s[i]=='(')f0=1,f1=0;
		if(s[i]==')')f0=0,f1=1;
		for(int j=0;j<n+m;j++)if(f[i][j])
		{
			if(f0)upd(f[i+1][j+1],f[i][j]);
			if(f1&&j)upd(f[i+1][j-1],f[i][j]);
		}
	}
	return f[n+m-1][0];
}
int main()
{
	scanf("%d%d",&n,&m);cin>>p;p--;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)scanf("%d",&c[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)a[c[i][j]-1]=i+j;
	memset(s,0,sizeof s);
	for(int i=0;i<n*m;i++)if(!s[a[i]])
	{
		s[a[i]]='(';ll T=ff();
		if(T>p)continue;
		p-=T,s[a[i]]=')';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)putchar(s[i+j]);
		puts("");
	}
	return 0;
}