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
int n,p,tot,fre;
string s[41];
signed main()
{
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=n;i>=1;i--)
	{
		tot*=2;
		if(s[i]=="halfplus")
		{
			fre++; 
			tot++; 
		}
	}
	cout<<(2*tot-fre)*p/2;
	return 0;
}