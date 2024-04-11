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
int t,n,last;
string a;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		cin>>a;
		cout<<1;
		last=1;
		for(int i=1;i<a.size();i++)
		{
			if(a[i-1]=='0'&&a[i]=='1')
				last=1;
			else
				if(a[i-1]==a[i])
					last^=1;
			cout<<last;
		}
		cout<<endl;
	}
	return 0;
}