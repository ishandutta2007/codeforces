#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
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
int n,one,a[1001],pri[2000001];
vector<int> p;
signed main()
{
	n=read();
	for(int i=2;i<=2000000;i++)
	{
		if(!pri[i])
			p.push_back(i);
		for(int l:p)
		{
			if(i*l>2000000)
				break;
			pri[i*l]=1;
			if(i%l==0)
				break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1)
			one++;
	}
	if(one)
	{
		for(int i=1;i<=n;i++)
			if(a[i]!=1&&!pri[a[i]+1])
			{
				cout<<one+1<<endl<<a[i];
				while(one--)
					cout<<" 1";
				return 0;
			}
		if(one!=1)
		{
			cout<<one<<endl;
			while(one--)
				cout<<"1 ";		
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			if(!pri[a[i]+a[l]])
			{
				cout<<"2\n"<<a[i]<<" "<<a[l];
				return 0;
			}
	cout<<"1\n"<<a[1];
	return 0;
}