#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int maxn=1000010;

long long c1[maxn];
long long c2[maxn];

void upd1(int pos, long long val)
{
	while (pos<maxn)
		c1[pos]+=val, pos+=pos&(-pos);
}

void upd2(int pos, long long val)
{
	while (pos<maxn)
		c2[pos]+=val, pos+=pos&(-pos);
}

long long get1(int pos)
{
	long long ret = 0;
	while (pos)
		ret += c1[pos], pos-=pos&(-pos);
	return ret;
}

long long get2(int pos)
{
	long long ret = 0;
	while (pos)
		ret += c2[pos], pos-=pos&(-pos);
	return ret;
}

int BS(int k)
{
	int l=1, r=1000000,mid;

	while (l<r)
	{
		mid = (l+r)/2;
		if (get1(mid)>=k)
			r=mid;
		else
			l=mid+1;
	}
	return r;
}

vector<pair<int, int> > vec[maxn];
int main()
{
	int n,k,m;

	scanf("%d%d%d",&n,&k,&m);

	for (int i=1;i<=m;i++)
	{
		int l,r,c,p;
		scanf("%d%d%d%d",&l,&r,&c,&p);

		vec[l].push_back(make_pair(c, p));
		vec[r+1].push_back(make_pair(-c, p));
	}

	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<vec[i].size();j++)
		{
			int cnt = vec[i][j].first;
			int price = vec[i][j].second;
			upd1(price, cnt);
			upd2(price, cnt*(long long)price);
		}
		int price = BS(k);
		
		long long supply = get1(price);
		if (supply<k)
		{
			ans+=get2(price);
		}
		else
		{
			long long left = supply - k;
			ans += get2(price)-left*price;
		}
	}
	cout<<ans<<endl;
}