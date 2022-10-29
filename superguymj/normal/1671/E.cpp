#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=500005,mod=998244353;
int n,d;
char s[N];
string str[N];
LL f[N];

void dfs(int x)
{
	if((x<<1)>n) {f[x]=1; return;}
	dfs(x<<1);
	dfs(x<<1|1);
	if(str[x<<1]==str[x<<1|1])
	{
		f[x]=f[x<<1]*f[x<<1]%mod;
		str[x]=str[x]+str[x<<1]+str[x<<1|1];
	}
	else
	{
		f[x]=f[x<<1]*f[x<<1|1]*2%mod;
		if(str[x<<1]<str[x<<1|1])
			str[x]=str[x]+str[x<<1]+str[x<<1|1];
		else
			str[x]=str[x]+str[x<<1|1]+str[x<<1];
	}
}	

int main()
{
	scanf("%d",&d),n=(1<<d)-1;
	scanf("%s",s+1);
	rep(i,1,n) str[i]=s[i];
	dfs(1);
	printf("%lld\n",f[1]);
	return 0;
}