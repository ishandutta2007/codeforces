#include<cstdio>
#include<iostream>
#include<cstring>
#define N 1025
using namespace std;
int n,x,y,res,st[N],tot,c,tmp=1;
int st2[N],tot2;
int p1,p2;
void Ask()
{
	c=0;
	while(st[c]<=n&&c<tot)c++;
	if(c)
	{
		printf("? %d",c);
		for(int i=0;i<c;i++)
		printf(" %d",st[i]);
		printf("\n");
		fflush(stdout);
		scanf("%d",&res);
		if(res==-1)exit(0);
	}
	else res=0;
	for(int i=c;i<tot;i++)
	res^=x;
	if(res&&res!=y)res^=x;
}
int find1(int l,int r)
{
	if(l==r)return st2[l];
	int mid=(l+r)>>1;
	tot=0;
	for(int i=l;i<=mid;i++)
	st[tot++]=st2[i];
	Ask();
	if(res)return find1(l,mid);
	else return find1(mid+1,r);
}
void find2(int len)
{
	tot=0;
	for(int i=1;i<tmp;i+=(len<<1))
	for(int j=0;j<len;j++)
	st[tot++]=i+j;
	Ask();
	if(res)
	{
		tot2=tot;
		for(int i=0;i<tot;i++)
		st2[i]=st[i];
		p1=find1(0,tot2-1);
		int tp=len+1;
		while(tp<p1)
		tp+=(len<<1);
		tot2=0;
		for(int i=tp;i<tp+len;i++)
		st2[tot2++]=i;
		p2=find1(0,tot2-1);
	}
	else find2(len>>1);
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	while(tmp<n)
	tmp<<=1;
	find2(tmp>>1);
	printf("! %d %d",p1,p2);return 0;
}