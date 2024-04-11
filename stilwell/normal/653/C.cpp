#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ans;
int a[200005],b[200005];
bool c[200005];

void add(int x){if(x!=b[m])b[++m]=x;c[x]=true;}

bool check_(int w)
{
	if(w<1||w>=n)return true;
	if(w&1)
	{
		if(a[w]>=a[w+1])return false;
	}
	else
	{
		if(a[w]<=a[w+1])return false;
	}
	return true;
}
bool check(int x)
{
	int i;
	if(!check_(x-1))return false;
	if(!check_(x))return false;
	for(i=1;i<=m;++i)
	{
		if(!check_(b[i]-1))return false;
		if(!check_(b[i]))return false;
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<n;++i)
	if(i&1)
	{
		if(a[i]>=a[i+1])add(i),add(i+1);
	}
	else
	{
		if(a[i]<=a[i+1])add(i),add(i+1);
	}
	if(m<=7)
	{
		for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
		{
			if(j<=b[i]&&c[j])continue;
			swap(a[b[i]],a[j]);
			if(check(j))++ans;
			swap(a[b[i]],a[j]);
		}
	}
	printf("%d\n",ans);
}