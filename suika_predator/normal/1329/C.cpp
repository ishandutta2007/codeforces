#include<bits/stdc++.h>
using namespace std;
int n,h,g,k,T;
int a[1111111],mark[1111111];
long long sum;
pair<vector<int>,int> solve(int dep,int id)
{
	vector<int> ret;
	ret.push_back(a[id]);
	if(dep==h)
	{
		return make_pair(ret,0);
	}
	auto _=solve(dep+1,id*2);
	vector<int> &L=_.first;
	int lmax=_.second;
	auto __=solve(dep+1,id*2+1);
	vector<int> &R=__.first;
	int rmax=__.second;
	int i=0,j=0;
	while(i<L.size()&&j<R.size())
	{
		if(L[i]>R[j])
			ret.push_back(L[i]),i++;
		else
			ret.push_back(R[j]),j++;
	}
	while(i<L.size())
		ret.push_back(L[i]),i++;
	while(j<R.size())
		ret.push_back(R[j]),j++;
	while(ret.back()<lmax||ret.back()<rmax)ret.pop_back();
//	cerr<<"solve "<<dep<<' '<<id<<":";
//	cerr<<lmax<<' '<<rmax<<endl;
//	for(auto x:ret)cerr<<' '<<x;cerr<<endl;
	int qwq=0;
	if(dep<=g)
	{
		qwq=ret.back();
		sum+=qwq;
		mark[qwq]=1;
		ret.pop_back();
	}
	return make_pair(ret,qwq);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&h,&g);
		n=(1<<h)-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sum=0;
		solve(1,1);
//		for(int i=1;i<=n;i++)cerr<<a[i]<<' '<<mark[a[i]]<<endl;
		printf("%lld\n",sum);
		for(int i=n;i>=1;i--)
		{
			if(!mark[a[i]])
			{
				printf("%d ",i);
			}
			mark[a[i]]=0;
		}
		printf("\n");
	}
	return 0;
}