#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

//s.max_load_factor(0.25);s.reserve(2048);

const long long N = 200001;

struct rectangle
{
	pair<long long,long long> l,r;
};

rectangle p[N];

bool intersect(rectangle a,rectangle b)
{
	if(a.l.first>b.r.first || a.l.second>b.r.second)
		return 0;

	if(b.l.first>a.r.first || b.l.second>a.r.second)
		return 0;

	return 1;
}

rectangle left(rectangle a,rectangle b)
{
	a.l.first=max(a.l.first,b.l.first);
	a.l.second=max(a.l.second,b.l.second);
	a.r.first=min(a.r.first,b.r.first);
	a.r.second=min(a.r.second,b.r.second);

	return a;
}

bool valid(rectangle a)
{
	if(a.l.first>a.r.first)
		return 0;
	if(a.l.second>a.r.second)
		return 0;

	return 1;
}

rectangle prefix[N],suffix[N];

int main ()
{
	long long n,i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(i=0;i<n;i++)
		cin>>p[i].l.first>>p[i].l.second>>p[i].r.first>>p[i].r.second;

	prefix[0]=p[0];

	for(i=1;i<n;i++)
		prefix[i]=left(prefix[i-1],p[i]);

	suffix[n-1]=p[n-1];

	for(i=n-2;i>=0;i--)
		suffix[i]=left(suffix[i+1],p[i]);

	if(valid(suffix[1]))
	{
		cout<<suffix[1].l.first<<" "<<suffix[1].l.second<<"\n";
		return 0;
	}

	if(valid(prefix[n-2]))
	{
		cout<<prefix[n-2].l.first<<" "<<prefix[n-2].l.second<<"\n";
		return 0;
	}

	rectangle x;

	for(i=1;i<n-1;i++)
	{
		x=left(prefix[i-1],suffix[i+1]);

		if(valid(x))
		{
			cout<<x.l.first<<" "<<x.l.second<<"\n";
			return 0;
		}
	}

	return 0;
}