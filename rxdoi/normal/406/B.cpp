#include<cstdio>
using namespace std;

const int Max=1e6+19,tot=1e6+1;
int use[Max],n,x,sol[Max],Ans,now=1;

int main()
{
	scanf("%d",&n);
	while (n--) scanf("%d",&x),use[x]=1;
	for (int i=1;i<tot;i++)
		if (use[i]==1)
			if (!use[tot-i]) 
			{
				use[tot-i]=-1;
				sol[Ans++]=tot-i;
			} else
			{
				while (use[now]||use[tot-now]) now++;
				use[now]=use[tot-now]=-1;
				sol[Ans++]=now;sol[Ans++]=tot-now;
				use[tot-i]=0;
			}
	printf("%d\n",Ans);
	while (--Ans>=0) printf("%d ",sol[Ans]);
}