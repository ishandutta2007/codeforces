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
int n,q,flp;
deque<int> a,f,b;
vector<int> v;
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a.push_back(1);
	f.push_back(0);
	b.push_back(0);
	for(int i=1;i<=n;i++)
	{
		f.push_back(i);
		b.push_back(i);
	} 
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int p=read();
			if(p*2>a.size())
			{
				flp^=1;
				p=a.size()-p;
			}
			if(flp)
			{
				v.clear();
				for(int i=1;i<=p;i++)
				{
					v.push_back(a.back());
					a.pop_back();
					f.pop_back();
					b.pop_front();
				}
				b[0]=0;
				for(int i=1;i<=p;i++)
				{
					a[a.size()-i]+=v.back();
					v.pop_back();
					b[i]=b[i-1]+a[a.size()-i];
				}
				for(int i=p;i>=1;i--)
					f[f.size()-i]=f[f.size()-1-i]+a[a.size()-i];
			}
			else
			{
				v.clear();
				for(int i=1;i<=p;i++)
				{
					v.push_back(a.front());
					a.pop_front();
					f.pop_front();
					b.pop_back();
				}
				f[0]=0;
				for(int i=0;i<p;i++)
				{
					a[i]+=v.back();
					v.pop_back();
					f[i+1]=f[i]+a[i];
				}
				for(int i=p;i>=1;i--)
					b[b.size()-i]=b[b.size()-1-i]+a[i-1]; 
			}
		}
		else
		{
			int l=read(),r=read();
			if(flp)
				cout<<b[r]-b[l]<<endl;
			else
				cout<<f[r]-f[l]<<endl;
		}
	}
	return 0;
}