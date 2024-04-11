#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a1[1005],a2[1005],b1[1005],b2[1005];
int n,a,b,i,j,k,l,tot1,tot2;
int u1,u2,u3,v1,v2,v3;
int k1[10],k2[10];
int len[5];

int sqr(int x){return x*x;}
bool check()
{
	if(u1==u2)return false;
	if(u2==u3)return false;
	if(u3==u1)return false;
	if(v1==v2)return false;
	if(v2==v3)return false;
	if(v3==v1)return false;
	len[1]=sqr(u2-u1)+sqr(v2-v1);
	len[2]=sqr(u3-u2)+sqr(v3-v2);
	len[3]=sqr(u1-u3)+sqr(v1-v3);
	if(len[3]<=len[1])return false;
	if(len[3]<=len[2])return false;
	//sort(len+1,len+3+1);
	if(len[1]+len[2]==len[3])
	return true;else return false;
}

void print_ans()
{
	printf("YES\n");
	printf("%d %d\n",u1,v1);
	printf("%d %d\n",u2,v2);
	printf("%d %d\n",u3,v3);
}

int main()
{
	scanf("%d%d",&a,&b);
	n=max(a,b);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(i*i+j*j==a*a)
		{
			++tot1;
			a1[tot1]=i;
			a2[tot1]=j;
		}
		if(i*i+j*j==b*b)
		{
			++tot2;
			b1[tot2]=i;
			b2[tot2]=j;
		}
	}
	k1[1]=1;k2[1]=1;
	k1[2]=1;k2[2]=-1;
	k1[3]=-1;k2[3]=1;
	k1[4]=-1;k2[4]=-1;
	u1=0;v1=0;
	for(i=1;i<=tot1;++i)
	for(j=1;j<=tot2;++j)
	for(k=1;k<=4;++k)
	for(l=1;l<=4;++l)
	{
		u2=u1+k1[k]*a1[i];
		v2=v1+k2[k]*a2[i];
		u3=u2+k1[l]*b1[j];
		v3=v2+k1[l]*b2[j];
		if(check())
		{
			print_ans();
			return 0;
		}
		u2=u1+k1[l]*b1[j];
		v2=v1+k1[l]*b2[j];
		u3=u2+k1[k]*a1[i];
		v3=v2+k2[k]*a2[i];
		if(check())
		{
			print_ans();
			return 0;
		}
	}
	printf("NO\n");
}