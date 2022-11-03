#include <cstdio>
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

map<int,map<int,vector<int> > > mim;
int n,m,a[123],b[123],c[123],q,u[123],v[123];
set<int> dp[123][123];
bool llg[123][123][123];

inline void findof(int colour,int vertex,vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		if(!llg[colour][vertex][v[i]])
		{
			dp[vertex][v[i]].insert(colour);
			llg[colour][vertex][v[i]]=true;
			findof(colour,vertex,mim[colour][v[i]]);
		}
	}
}
/*
inline void init()
{
	for(map<int,map<int,vector<int> > >::iterator it=mim.begin();it!=mim.end();it++)
	{
		map<int,vector<int> > miv=it->second;
		for(map<int,vector<int> >::iterator it2=miv.begin();it2!=miv.end();it2++)
		{
			vector<int> vi=it2->second;
			findof(it->first,it2->first,vi);
		}
	}
}
*/
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		mim[c[i]][a[i]].push_back(b[i]);
		mim[c[i]][b[i]].push_back(a[i]);
	}
	for(map<int,map<int,vector<int> > >::iterator it=mim.begin();it!=mim.end();it++)
	{
		map<int,vector<int> > miv=it->second;
		for(map<int,vector<int> >::iterator it2=miv.begin();it2!=miv.end();it2++)
		{
			vector<int> vi=it2->second;
			findof(it->first,it2->first,vi);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&u[i],&v[i]);
		printf("%d\n",dp[u[i]][v[i]].size());
	}
	return 0;
}