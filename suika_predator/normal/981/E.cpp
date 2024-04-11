#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MOD=998244353;
int poly[23333],ans[23333];
vector<int> mod[23333][2];
int n,q,l,r,d;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&d);
		mod[l][0].push_back(d);
		mod[r+1][1].push_back(d);
	}
	poly[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto x:mod[i][0])
		{
			for(int j=n-x;j>=0;j--)
			{
				poly[j+x]=(poly[j+x]+poly[j])%MOD;
			}
		}
		for(auto x:mod[i][1])
		{
			for(int j=0;j<=n-x;j++)
			{
				poly[j+x]=(poly[j+x]-poly[j]+MOD)%MOD;
			}
		}
		for(int j=1;j<=n;j++)ans[j]=ans[j]|(poly[j]!=0);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(ans[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}