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
bool ispri(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int t,k;
signed main()
{
	t=read();
	while(t--)
	{
		k=read();
		int a,b;
		for(a=k+1;ispri(a)==0;a++);
		for(b=a+k;ispri(b)==0;b++);
		cout<<a*b<<endl;	
	} 
	return 0;
}