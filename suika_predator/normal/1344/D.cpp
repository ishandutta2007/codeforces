#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k;
inline long long calc(long long a,long long x)
{
	return a-3*x*x+3*x-1;
}
int a[111111],b[111111];
long long gao(long long d)//put >=d in
{
//	cerr<<"gao "<<d<<endl;
	long long ret=0;
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=a[i];
		while(l<r)
		{
//			cerr<<l<<' '<<r<<endl;
			long long mid=(l+r+1)/2;
			if(calc(a[i],mid)>=d)l=mid;
			else r=mid-1;
		}
//		cerr<<"b["<<i<<"]="<<l<<endl;
		b[i]=l;
		ret+=l;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	long long l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(l,calc(a[i],a[i]));
		r=max(r,calc(a[i],1));
	}
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(mid<0&&(l+r)%2==-1)mid--;
//		cerr<<l<<' '<<r<<' '<<mid<<endl;
		long long sum=gao(mid);
		if(sum>k)l=mid+1;
		else r=mid;
	}
	long long sum=gao(l);
//	cerr<<l<<' '<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<' '<<a[i]<<' '<<b[i]<<' '<<calc(a[i],b[i])<<' '<<calc(a[i],b[i]+1)<<endl;
		if(sum<k&&calc(a[i],b[i]+1)==l-1)
		{
			cout<<b[i]+1<<' ';
			sum++;
		}
		else
		{
			cout<<b[i]<<' ';
		}
	}
	return 0;
}