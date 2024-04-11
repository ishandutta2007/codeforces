#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
// const int INF=4e18;
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
int n,k,cnt,a[100010],num[10000010],num2[10000010];
std::vector<int> p,v[100010],v1[100010];
bool ok[10000010];
signed main()
{
	for(int i=2;i<=10000000;i++)
	{
		if(!ok[i])
			p.push_back(i);
		for(int l:p)
		{
			if(i*l>10000000)
				break;
			ok[i*l]=1;
			if(i%l==0)
				break;
		}
	}
	// return 0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		int x=a[i];
		for(int l:p)
		{
			if(l*l>x)
				break;
			if(x%l==0)
			{
				v[i].push_back(l);
				while(x%l==0)
					x/=l;
			}
		}
		if(x!=1)
			v[i].push_back(x);
		for(int l:v[i])
			num2[l]++;
		int k=v[i].size();
		for(int l=1;l<(1<<k);l++)
		{
			int tot=1;
			for(int j=0;j<k;j++)
				if((l>>j)&1)
					tot*=v[i][j];
			v1[i].push_back(tot);
			if(__builtin_parity(l))
				num[tot]++;
			else
				num[tot]--;
		}
	}
	// return 0;
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int l:v1[i])
			tot+=num[l];
		if(n-tot+1>=k)
		{
			cout<<i<<" ";
			for(int j=1,l=k-1;l;j++)
				if(__gcd(a[i],a[j])==1)
				{
					l--;
					cout<<j<<" ";
				}
			return 0;
		}
	}
	for(int i:p)
		if(num2[i]>=k)
		{
			for(int l=1,j=k;j;l++)
				if(a[l]%i==0)
				{
					j--;
					cout<<l<<" ";
				}
			return 0;
		}
	return 0;
}