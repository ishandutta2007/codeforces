#include<bits/stdc++.h>
#define ls (x<<1)
#define rs ((x<<1)+1)
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=(1<<21)+50;
ll T,n,m,top,num;
ll h[N],pl[N],pos[N],dy[N],stk[N],ans[N];
bool cmp(const ll &a,const ll &b){return h[a]>h[b];}
void mtry(ll id)
{
	ll sx,x,i;
	sx=pos[id];
	top=0;
	x=sx;
	while(ls<=n&&rs<=n&&(dy[ls]||dy[rs]))
	{
		stk[++top]=x;
		if(h[dy[ls]]>h[dy[rs]]) x=ls;
		else x=rs;
	}
	stk[++top]=x;
	if(x<=m) return ;
	for(i=1;i<top;i++) pos[dy[stk[i+1]]]=stk[i];
	for(i=1;i<top;i++) dy[stk[i]]=dy[stk[i+1]];
	dy[stk[top]]=0;
	ans[++num]=sx;
}
void Solve()
{
	ll i,j,S=0;
	n=rd();m=rd();
	n=(1<<n)-1;m=(1<<m)-1;
	for(i=1;i<=n;i++) h[i]=rd();
	for(i=1;i<=n;i++) pl[i]=i,pos[i]=i,dy[i]=i;
	sort(pl+1,pl+n+1,cmp);
	num=0;
	for(i=1;i<=n;i++)
	{
		mtry(pl[i]);
		//for(j=1;j<=n;j++) printf("%lld ",dy[j]);
		//putchar('\n');
	}
	for(i=1;i<=m;i++) S+=h[dy[i]];
	printf("%lld\n",S);
	//printf("num %lld\n",num);
	for(i=1;i<=num;i++) printf("%lld ",ans[i]);
	putchar('\n');
}
int main()
{
	T=rd();
	while(T--) Solve();
}