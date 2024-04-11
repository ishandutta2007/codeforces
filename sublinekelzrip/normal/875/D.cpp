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
#include<bitset>
using namespace std;
int num[200010],gc[200010][25];
int nex[200010]; 
int get(int l,int r)
{
	if(l==r)
		return num[l];
	int lg=(int)(log(r-l+1.5)/log(2.0));
	return gc[l][lg]|gc[r-(1<<lg)+1][lg];
}
int hx[200010],pre[200010],md[1050010],k=0,nm[200010];
void insert(int i,int z)
{
	int j=i%1020407;
	k++;
	hx[k]=i;
	pre[k]=md[j];
	md[j]=k;
	nm[k]=z;
}
int get(int i)
{
	for(int j=md[i%1020407];j;j=pre[j])
		if(hx[j]==i)
		{
			return j;
		}
	return 0;
}
int main()
{
	int n,q=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		gc[i][0]=num[i];
	}
	for(int i=n;i>=1;i--)
	{
		int t;
		if(t=get(num[i]))
		{
			nex[i]=nm[t];
			nm[t]=i;
		}
		else
		{
			nex[i]=n+1;
			insert(num[i],i);
		}
	}
	for(int j=1;j<=20;j++)
		for(int k=1;k+(1<<j)-1<=n;k++)
			gc[k][j]=gc[k][j-1]|gc[k+(1<<(j-1))][j-1];
	long long ans=n*1ll*(n+1)/2;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l!=r)
		{
			int mid=(l+r)>>1;
			if(get(mid,i)==num[i])
				r=mid;
			else
				l=mid+1;
		}
		int x=l;
		l=i,r=nex[i]-1;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if(get(i,mid)==num[i])
				l=mid;
			else
				r=mid-1;
		}
		ans=ans-(i-x+1)*1ll*(l-i+1);
	}
	cout<<ans;
}