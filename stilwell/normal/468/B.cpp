#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

map <int,int> Hash;

int n,a,b,i,j,k,T;
int num[100005],A[100005],B[100005],vis[100005];
bool ans[100005],viss[100005],f1,f2,f;

bool dfsA(int x)
{
	if(vis[x]==T)return true;
	if(!x)return true;
	if(!A[x])return false;
	vis[x]=T;
	return dfsA(B[A[x]]);
}

bool dfsB(int x)
{
	if(vis[x]==T)return true;
	if(!x)return true;
	if(!B[x])return false;
	vis[x]=T;
	return dfsB(A[B[x]]);
}

void fill(int x)
{
	if(!x)return;
	if(viss[x])return;
	ans[x]=f;viss[x]=true;
	fill(A[x]);
	fill(B[x]);
}

bool tryA(int i)
{
	if(!A[i])return false;
	++T;f1=dfsA(B[i]);
	++T;f2=dfsA(B[A[i]]);
	if(f1&&f2)
	{
		f=false;
		fill(i);
	}
	return f1&&f2;
}

bool tryB(int i)
{
	if(!B[i])return false;
	++T;f1=dfsB(A[i]);
	++T;f2=dfsB(A[B[i]]);
	if(f1&&f2)
	{
		f=true;
		fill(i);
	}
	return f1&&f2;
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;++i)scanf("%d",&num[i]),Hash[num[i]]=i;
	for(i=1;i<=n;++i)
	{
		A[i]=Hash[a-num[i]];
		B[i]=Hash[b-num[i]];
	}
	for(i=1;i<=n;++i)
	if(!viss[i])
	{
		if(!tryA(i))
		{
			if(!tryB(i))
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(i=1;i<=n;++i)
	{
		printf("%d",ans[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}
}