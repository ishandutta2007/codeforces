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
int mod=1e9+7;
int qp(int x,int y)
{
	if(y==0)
		return 1;
	if(x==1)
		return x;
	if(y==1)
		return x;
	int ans=qp(x,y/2);
	(ans*=ans)%=mod;
	if(y&1)
		(ans*=x)%=mod;
	return ans; 
}
signed main()
{
	int n=read();
	int k=read();
	cout<<qp(k,k-1)*qp(n-k,n-k)%mod;
	return 0;
}