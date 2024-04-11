#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct qwq
{
	int l,r,id;
	inline bool operator<(const qwq &x)const{return r<x.r;}
}op[233333];
inline bool cmp(const qwq &x,const qwq &y)
{
	return x.l<y.l;
}
int n,m,fl[233333];
priority_queue<qwq> pq;
int ok[2333333];
int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		op[i].l=x;op[i].r=x+y-1;op[i].id=i;
		ok[op[i].l]++;ok[op[i].r+1]--;
	}
	for(int i=1;i<=n;i++)ok[i]+=ok[i-1];
	sort(op+1,op+m+1,cmp);
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(op[j].l==i)pq.push(op[j]),j++;
		if(!ok[i])continue;
		if(ok[i]!=-1)
		{
			qwq cur=pq.top();pq.pop();
			for(int k=i;k<=cur.r;k++)ok[k]=-1;
			fl[cur.id]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(fl[i]==0)cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++)
	{
		if(fl[i]==0)printf("%d ",i);
	}
	return 0;
}