#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

int n,m,q,n1,n2,v,i,j,k,a1,a2,b1,b2,ans;

set<int> S[2];
set<int> :: iterator iter;

int cal(int x,int y){return x/y+(x%y!=0);}
void workL(int x,int v)
{
	iter=S[x].lower_bound(b1);--iter;
	if(*iter<1)return;
	int now=abs(b1-*iter)+abs(b2-*iter)+cal(abs(a1-a2),v);
	if(now<ans)ans=now;
}
void workR(int x,int v)
{
	iter=S[x].lower_bound(b1);
	if(*iter>m)return;
	int now=abs(b1-*iter)+abs(b2-*iter)+cal(abs(a1-a2),v);
	if(now<ans)ans=now;
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&v);
	for(;n1;--n1)scanf("%d",&k),S[0].insert(k);
	for(;n2;--n2)scanf("%d",&k),S[1].insert(k);
	S[0].insert(0);S[0].insert(m+1);
	S[1].insert(0);S[1].insert(m+1);
	scanf("%d",&q);
	for(;q;--q)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(a1==a2)ans=abs(b1-b2);
		else
		{
			ans=1000000000;
			workL(0,1);workR(0,1);
			workL(1,v);workR(1,v);
			swap(a1,a2);swap(b1,b2);
			workL(0,1);workR(0,1);
			workL(1,v);workR(1,v);
		}
		printf("%d\n",ans);
	}
}