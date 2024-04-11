#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int n,m,i,j,k,n0,n1;
int q0[1000005],q1[1000005],l0,l1,r0,r1;
char s[1000005];

void fail()
{
	printf("-1\n");
	exit(0);
}

vector<int> V[200005];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(i=1;i<=n;++i)if(s[i]=='0')++n0;else ++n1;
	if(n1>=n0)fail();
	m=n0-n1;l0=l1=1;
	for(i=1;i<=m;++i)q0[++r0]=i;
	for(i=1;i<=n;++i)
	if(s[i]=='0')
	{
		if(l0>r0)fail();
		V[q0[l0]].push_back(i);
		q1[++r1]=q0[l0];
		++l0;
	}
	else
	{
		if(l1>r1)fail();
		V[q1[l1]].push_back(i);
		q0[++r0]=q1[l1];
		++l1;
	}
	if(l0<=r0)fail();
	printf("%d\n",m);
	for(i=1;i<=m;++i)
	{
		printf("%d",V[i].size());
		for(j=0;j<V[i].size();++j)printf(" %d",V[i][j]);
		printf("\n");
	}
}