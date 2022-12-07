#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,tot=0,c0=0,c1=0,c2=0,c3=0,num=0;
char s[N];
int t[N],top[2],stk[2][N],p0[N],p1[N],p2[N],p3[N],pl[N];
vector<int> vec[N];
struct Node{int id,w;}p[N];
void wrt(int id)
{
	for(int w:vec[id])
	{
		printf("%d ",w);
	}
}
int main()
{
	int i,c,id,id1,id2,now;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='R') t[i]=1;
	}
	for(i=1;i<=n;i++)
	{
		c=t[i];
		if(top[c^1]) 
		{
			id=stk[c^1][top[c^1]];
			vec[id].pb(i);
			top[c^1]--;
			stk[c][++top[c]]=id;
		}
		else
		{
			stk[c][++top[c]]=++tot;
			vec[tot].pb(i);
		}
	}
	for(i=1;i<=tot;i++)
	{
		p[i].id=i;p[i].w=0;
		if(t[vec[i][0]]==1) p[i].w+=2;
		if(t[vec[i].back()]==1) p[i].w+=1;
		if(p[i].w==0) p0[++c0]=i;
		if(p[i].w==1) p1[++c1]=i;
		if(p[i].w==2) p2[++c2]=i;
		if(p[i].w==3) p3[++c3]=i;
		//printf("solve %d\n",i);
		//for(int w:vec[i]) printf("%d ",w);
		//putchar('\n');
	}
	//exit(0);
	if(c1&&c2)
	{
		id1=p1[c1];id2=p2[c2];
		if(vec[id1].back()<vec[id2].back()) 
		{
			now=vec[id2].back();vec[id2].pop_back();vec[id1].pb(now);
		}
		else
		{
			now=vec[id1].back();vec[id1].pop_back();vec[id2].pb(now);
		}
	}
	for(i=1;i<=c1;i++) pl[++num]=p1[i];
	for(i=1;i<=c2;i++) pl[++num]=p2[i];
	printf("%d\n",tot-1);
	if(num>0)
	{
		now=t[vec[pl[1]][0]];
		if(now==1&&c0>c3) 
		{
			wrt(p0[c0]);c0--;
		}
		if(now==0&&c0<c3)
		{
			wrt(p3[c3]);c3--;
		}
	}
	for(i=1;i<=num;i++) wrt(pl[i]);
	now=0;
	if(num>0)
	{
		if(t[vec[pl[num]].back()]==0) now=1;
	}
	else 
	{
		if(c0<c3) now=1;
	}
	while(c0||c3)
	{
		
		if(now==0) wrt(p0[c0]),c0--;
		else wrt(p3[c3]),c3--;
		now^=1;
	}
	return 0;
}