#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define MN 400000
int x[MN+5],y[MN+5],l1[MN+5],r1[MN+5],l2[MN+5],r2[MN+5];
vector<int> v[MN+5];
int main()
{
	int n,i,j;long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=1e5;y[i]+=1e5;
		x[i]+=y[i];y[i]=x[i]-2*y[i];
		v[x[i]].push_back(y[i]);
	}
	for(i=0;i<=MN;++i)
	{
		if(i)l1[i]=l1[i-1],r1[i]=r1[i-1];else l1[i]=MN+1,r1[i]=-MN-1;
		if(i&1)for(j=0;j<v[i].size();++j)l1[i]=min(l1[i],v[i][j]+1),r1[i]=max(r1[i],v[i][j]-1);
	}
	for(i=MN;i;--i)
	{
		if(i<MN)l2[i]=l2[i+1],r2[i]=r2[i+1];else l2[i]=MN+1,r2[i]=-MN-1;
		if(i&1)for(j=0;j<v[i].size();++j)l2[i]=min(l2[i],v[i][j]+1),r2[i]=max(r2[i],v[i][j]-1);
		else if(max(l1[i],l2[i])<=min(r1[i],r2[i]))ans+=min(r1[i],r2[i])-max(l1[i],l2[i])+2>>1;
	}
	for(i=0;i<=MN;++i)
	{
		if(i)l1[i]=l1[i-1],r1[i]=r1[i-1];else l1[i]=MN+1,r1[i]=-MN-1;
		if(~i&1)for(j=0;j<v[i].size();++j)l1[i]=min(l1[i],v[i][j]+1),r1[i]=max(r1[i],v[i][j]-1);
	}
	for(i=MN;i;--i)
	{
		if(i<MN)l2[i]=l2[i+1],r2[i]=r2[i+1];else l2[i]=MN+1,r2[i]=-MN-1;
		if(~i&1)for(j=0;j<v[i].size();++j)l2[i]=min(l2[i],v[i][j]+1),r2[i]=max(r2[i],v[i][j]-1);
		else if(max(l1[i],l2[i])<=min(r1[i],r2[i]))ans+=min(r1[i],r2[i])-max(l1[i],l2[i])+2>>1;
	}
	printf("%I64d",ans);
}