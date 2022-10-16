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
int a,t,n,k,tt,b[200001]; 
map<int,int> m;
const int mod=1e9+7;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			b[i]=read();
		m.clear();
		m[0]=1;
		k=0;
		tt=1;
		for(int i=1;i<=n;i++)
		{
			a=m[k];
			m[k]=tt;
			k+=b[i];
			tt=(tt*2-a+mod)%mod;
		}
		cout<<tt<<endl;
	}
	return 0;
}