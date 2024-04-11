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
int n;
pair<int,string> p[51];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		p[i]=make_pair(read()*100-read()*50+read()+read()+read()+read()+read(),s);
	}
	sort(p+1,p+1+n);
	cout<<p[n].second;
	return 0;
}