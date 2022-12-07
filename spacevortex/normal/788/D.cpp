#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,S=1e8,inf=1e9;
int n,tot=0,w,t1=0,t2=0;
int p[N],l1[N],l2[N];
namespace GRD
{
	int n,m;
	int h1[N],h2[N];
	void init()
	{
		int i;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&h1[i]);
		for(i=1;i<=m;i++) scanf("%d",&h2[i]);
	}
	int qry(int x,int y)
	{
		int ras=inf,i;
		for(i=1;i<=n;i++) ras=min(ras,abs(x-h1[i]));
		for(i=1;i<=m;i++) ras=min(ras,abs(y-h2[i]));
		return ras;
	}
}
int qry(int x,int y)
{
	//return GRD::qry(x,y);
	int ret;
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
void solve(int l,int r)
{
	int p1,p2,d1,d2,top=0,i,id=inf;
	int a[5];
	p1=floor((double)(l+r)/2.0);
	p2=p1+1;
	d1=qry(p1,p1);d2=qry(p2,p2);
	if(d1==d2)
	{
		a[++top]=p1-d1;a[++top]=p2+d2;
	}
	else if(d1<d2) a[++top]=p1-d1;
	else a[++top]=p2+d2;
	for(i=1;i<=top;i++)
	{
		if(a[i]!=l&&a[i]!=r) id=a[i];
	}
	if(id==inf) return ;
	p[++tot]=id;
	solve(l,id);solve(id,r);
}
int main()
{
	//freopen("a.in","r",stdin);
	//GRD::init();
	int i;
	//puts("OK");
	if(qry(S,S)==0) p[++tot]=S;
	if(qry(-S,-S)==0) p[++tot]=-S;
	solve(-S,S);
	sort(p+1,p+tot+1);
	p[0]=-S-1;p[tot+1]=S+1;
	for(i=1;i<=tot+1;i++)
	{
		if(p[i]>=p[i-1]+2) w=p[i]-1; 
	}
	for(i=1;i<=tot;i++)
	{
		if(qry(p[i],w)==0) l2[++t2]=p[i];
		if(qry(w,p[i])==0) l1[++t1]=p[i];
	}
	
	printf("1 %d %d\n",t2,t1);
	for(i=1;i<=t2;i++) printf("%d ",l2[i]);putchar('\n');
	for(i=1;i<=t1;i++) printf("%d ",l1[i]);
	return 0;
}