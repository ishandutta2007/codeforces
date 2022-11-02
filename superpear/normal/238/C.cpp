#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int maxlongint=2147483647;

vector<pair<int,int> > f[5000];
int n,xc,yc,ans,ans1,ans2;
int x[5000],y[5000],hash[5000],fa[5000],sum[5000];

void doit(int s)
{
	int q;
	for (int i=0;i<f[s].size();i++)
	{
		q=f[s][i].first;
		if ((fa[s]!=q)&&(hash[q]==0))
		{
			fa[q]=s;
			doit(q);
			sum[s]+=sum[q];
			if (f[s][i].second==-1) ++sum[s];
		}
	}
}

void search(int s,int nowans)
{
	ans1=min(ans1,nowans);
	int q;
	for (int i=0;i<f[s].size();i++)
	{
		q=f[s][i].first;
		if ((fa[s]!=q)&&(hash[q]==0))
		{
			if (f[s][i].second==1) search(q,nowans+1); else search(q,nowans-1);
		}
	}
}

int main()
{
	//freopen("C.in","r",stdin);
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>xc>>yc;
		f[xc].push_back(make_pair(yc,1));
		f[yc].push_back(make_pair(xc,-1));
		x[i]=xc;y[i]=yc;
	}
	ans=maxlongint;
	for (int i=1;i<n;i++)
	{
		memset(hash,0,sizeof(hash));
		memset(fa,0,sizeof(fa));
		memset(sum,0,sizeof(sum));
		hash[x[i]]=1;hash[y[i]]=1;
		doit(x[i]);
		ans1=maxlongint;
		search(x[i],sum[x[i]]);
		ans2=ans1;ans1=maxlongint;
		doit(y[i]);
		search(y[i],sum[y[i]]);
		ans=min(ans,ans1+ans2);
	}	
	if (n==1) cout<<0<<endl; else cout<<ans<<endl;
	
	return 0;
}