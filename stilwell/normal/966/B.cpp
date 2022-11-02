#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,v1,v2,i,j,k;
bool flag;

vector<int> V[2];

struct node
{
	int c,id;
}t[600005];
inline bool cmp(const node &a,const node &b){return a.c>b.c;}

void work(int x,int val)
{
	//long long sum=0;
	int cnt=0;
	for(;;)
	{
		++m;
		if(m>n)
		{
			flag=true;
			return;
		}
		//sum+=t[m].c;
		++cnt;
		V[x].push_back(t[m].id);
		//printf("%d %d %d\n",val,cnt,t[m].c);
		if(val/cnt+(val%cnt!=0)<=t[m].c)return;
	}
}

void print()
{
	printf("Yes\n");
	printf("%d %d\n",V[0].size(),V[1].size());
	for(i=0;i<=1;++i)
	{
		for(j=0;j<V[i].size();++j)printf("%d ",V[i][j]);
		printf("\n");
	}
	exit(0);
}

int main()
{
	scanf("%d%d%d",&n,&v1,&v2);
	for(i=1;i<=n;++i)scanf("%d",&t[i].c),t[i].id=i;
	sort(t+1,t+n+1,cmp);
	work(0,v1),work(1,v2);
	if(!flag)print();
	flag=false;m=0;
	V[0].clear();V[1].clear();
	work(1,v2),work(0,v1);
	if(!flag)print();
	printf("No\n");
}