#include<bits/stdc++.h>
using namespace std;
long long a[50010],b[50010],c[50010],d[50010];
long long n;
long long maxn=0,maxm=0;
long long k;
long long tmp;
int main()
{
	cin>>n>>k;
	for (long long i=1;i<=n;++i) 
	{
		cin>>b[i];
		a[b[i]]++;
		d[i]=a[b[i]];
		maxn=max(maxn,b[i]);
	}
/*	for (long long i=1;i<=maxn;++i)
	{
		cout<<"a["<<i<<"]="<<a[i]<<endl;
		cout<<"b["<<i<<"]="<<b[i]<<endl;
		cout<<"c["<<i<<"]="<<c[i]<<endl;
		cout<<endl;
	}*/
	for (long long i=1;i<=maxn;i++)
	{
		maxm=max(maxm,a[i]);
	}
	if (maxm>k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		for (long long i=1;i<=maxn;++i)
		{
			tmp+=a[i];
			c[i]=(tmp-a[i])%k;
		}
		cout<<"YES"<<endl;
		for (long long i=1;i<=n;++i)
		{
			cout<<(c[b[i]]%k+d[i])%k+1<<" ";
		}
	}
	return 0ll;
 }