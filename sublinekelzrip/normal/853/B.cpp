#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
pair<pair<int,int>,pair<int,int> >p[300010];
int ar[300010],fi[300010];
long long fiar[1000010];
int main()
{
	int n,m,kk;
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&p[i].first.first,&p[i].first.second,&p[i].second.first,&p[i].second.second);
	sort(p+1,p+m+1);
	long long nowar,nowfi,ans=inf*1ll*inf;
	for(int i=1;i<=n;i++)
	{
		ar[i]=fi[i]=inf;
		nowar=nowfi=inf*1ll*n;
	}
	int k=0,hv=0;
	for(int i=1;i<=1000000;i++)
	{
		while(k<m&&p[k+1].first.first==i)
		{
			k++;
			if(p[k].first.second!=0)
			{
				if(ar[p[k].first.second]==inf)
					hv++;
				if(p[k].second.second<ar[p[k].first.second])
				{
					nowar=nowar-ar[p[k].first.second]+p[k].second.second;
					ar[p[k].first.second]=p[k].second.second;
				}
			}
		}
		if(hv==n)
			fiar[i]=nowar;
		else
			fiar[i]=inf*1ll*inf;
	}
	k=m+1;
	hv=0;
	for(int i=1000000;i>=1;i--)
	{
		while(k>1&&p[k-1].first.first==i)
		{
			k--;
			if(p[k].first.second==0)
			{
				if(fi[p[k].second.first]==inf)
					hv++;
				if(p[k].second.second<fi[p[k].second.first])
				{
					nowfi=nowfi-fi[p[k].second.first]+p[k].second.second;
					fi[p[k].second.first]=p[k].second.second;
				}
			}
		}
		if(hv==n)
			if(i>kk+1)
				ans=min(ans,fiar[i-kk-1]+nowfi);
	}
	if(ans<inf*1ll*n)
		cout<<ans;
	else
		cout<<-1;
	
}