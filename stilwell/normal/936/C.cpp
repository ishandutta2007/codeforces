#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,l,r;
int num[2005];
int ans[100005],tot;
char A[2005],B[2005],C[2005];
bool flag;

void Add(int x)
{
	if(!x)return;
	int i;
	ans[++tot]=x;
	for(i=1;i<=x;++i)C[i]=A[n-i+1];
	for(i=x+1;i<=n;++i)C[i]=A[i-x];
	for(i=1;i<=n;++i)A[i]=C[i];
}

void rev(int l,int r)
{
	//printf("%d %d\n",l,r);
	Add(n-r);
	Add(r-l+1);
	Add(l-1);
}

void revB()
{
	int i;
	for(i=1;i<=n/2;++i)swap(B[i],B[n-i+1]);
}

int main()
{
	scanf("%d",&n);
	scanf("%s",A+1);
	scanf("%s",B+1);
	for(i=1;i<=n;++i)++num[A[i]];
	for(i=1;i<=n;++i)--num[B[i]];
	for(i=1;i<=n;++i)
	if(num[A[i]]!=0)
	{
		printf("-1\n");
		return 0;
	}
	l=n/2+n%2;
	r=l+1;
	for(k=1;k<=n;++k)
	{
		if(k&1)
		{
			for(i=k;i<=n;++i)if(A[i]==B[l])break;
			--l;
		}
		else
		{
			for(i=k;i<=n;++i)if(A[i]==B[r])break;
			++r;
		}
		rev(k,i);
	}
	if(n&1)Add(n);
	//printf("%s\n",A+1);
	printf("%d\n",tot);
	for(i=1;i<=tot;++i)printf("%d ",ans[i]);
}