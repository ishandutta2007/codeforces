#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,T;
struct pr
{
	int a,t,id;
	inline bool operator<(const pr &x)const{return t<x.t;}
}p[233333];
vector<int> res;
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].a,&p[i].t);
		p[i].id=i;
	}
	sort(p+1,p+n+1);
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1,used=0,cnt=0;
		res.clear();
		for(int i=1;i<=n;i++)
		{
			//cout<<mid<<' '<<p[i].a<<endl;
			if(p[i].a>=mid)
			{
				used+=p[i].t;
				if(used>T)break;
				res.push_back(i);
				cnt++;
				if(cnt==mid)break;
			}
		}
		if(cnt<mid)r=mid-1;
		else l=mid;
	}
	res.clear();
	int used=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<mid<<' '<<p[i].a<<endl;
		if(p[i].a>=l)
		{
			used+=p[i].t;
			if(used>T)break;
			res.push_back(i);
			cnt++;
			if(cnt==l)break;
		}
	}
	printf("%d\n%d\n",res.size(),res.size());
	for(auto x:res)
	{
		printf("%d ",p[x].id);
	}
	printf("\n");
	return 0;
}