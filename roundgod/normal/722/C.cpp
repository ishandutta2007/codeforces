#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 100001
using namespace std;
typedef long long ll;
int parent[MAXN];
int height[MAXN],ord[MAXN];
ll sum[MAXN],ans[MAXN];
bool flag[MAXN];
ll res;
int n;

void init(const int& n)
{
	for (int i=0; i<n; ++i)
	{
		parent[i]=i;
		height[i]=0;
	}
}

int find(const int& x)
{
	if (parent[x]==x)
	{
		return x;
	}
	else
	{
		return parent[x]=find(parent[x]);
	}
}

void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	{
		return;
	}

	if (height[x]<height[y])
	{
	    sum[find(y)]=sum[find(x)]+sum[find(y)];
	    res=res>sum[find(y)]?res:sum[find(y)];
		parent[x]=y;
	}
	else
	{
        sum[find(x)]=sum[find(x)]+sum[find(y)];
        res=res>sum[find(x)]?res:sum[find(x)];
		parent[y]=x;
		if (height[x]==height[y])
		{
			++height[x];
		}
	}

}

bool same(const int& x, const int& y)
{
	return find(x) == find(y);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&sum[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&ord[i]);
    memset(flag,false,sizeof(flag));
    res=0;
    init(n);
    for(int i=n-1;i>=0;i--)
    {
        int j=ord[i]-1;
        flag[j]=true;
        res=res>sum[j]?res:sum[j];
        if(j!=0&&j!=n-1)
        {
            if(flag[j+1]) unite(j,j+1);
            if(flag[j-1]) unite(j,j-1);
        }
        else if(j==0)
        {
            if(flag[j+1]) unite(j,j+1);
        }
        else if(j==n-1)
        {
            if(flag[j-1]) unite(j,j-1);
        }
        ans[i]=res;
    }
    for(int i=1;i<n;i++)
        printf("%I64d\n",ans[i]);
    printf("0\n");
    return 0;
}