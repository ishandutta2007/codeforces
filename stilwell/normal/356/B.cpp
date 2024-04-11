#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long n,m;
int i,j,k,la,lb,lim;
char a[1000005],b[1000005];
int q[1000005],t,inc;
int inq[1000005],st;
long long tmp[27];
bool work[1000001];
long long ans;

int main()
{
	scanf("%I64d%I64d",&n,&m);
	if(n<m)
	{
		swap(n,m);
		scanf("%s",b);
		scanf("%s",a);
	}
	else
	{
		scanf("%s",a);
		scanf("%s",b);
	}
	la=strlen(a);
	lb=strlen(b);
	for(i=0;i<la;++i)
	if(!work[i])
	{
		t=0;
		for(j=0;j<26;++j)tmp[j]=0;
		for(j=i;;j=(j+la)%lb)
		{
			if(work[j])break;
			work[j]=true;
			q[++t]=j;inq[j]=t;
		}
		st=inq[j];
		if(t<=n)
		{
			for(j=1;j<=t;++j)
			++tmp[b[q[j]]-'a'];
			for(j=0;j<26;++j)tmp[j]*=n/t;
		}
		inc=(int)(n%t);
		for(j=inc;j>=1;--j)++tmp[b[q[j]]-'a'];
		ans+=tmp[a[i]-'a'];
		for(j=2;j<=t;++j)
		{
			--tmp[b[q[j-1]]-'a'];
			++inc;if(inc>t)inc=1;
			++tmp[b[q[inc]]-'a'];
			if(q[j]<la)ans+=tmp[a[q[j]]-'a'];
		}
	}
	ans=n*la-ans;
	printf("%I64d\n",ans);
	//system("pause");
}