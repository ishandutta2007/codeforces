#include<bits/stdc++.h>
using namespace std;
const int N=220;
int n,m;
namespace GRD
{
	int h[N];
	void init()
	{
		int i;
		for(i=1;i<=n;i++) scanf("%d ",&h[i]);
	}
	void qry(int w,int &x,int &y)
	{
		int i;
		h[w]++;
		x=y=0;
		for(i=1;i<=n;i++)
		{
			x+=h[i]*(h[i]-1)*(h[i]-2)/6;
			y+=h[i]*h[i+1]*h[i+2];
		}
	}
}
int a[N],b[N],p[N],pl[N],s[N];
int qvl(int w)
{
	return lower_bound(pl+1,pl+m+1,w)-pl;
}
void qry(int w,int &x,int &y)
{
	//return GRD::qry(w,x,y);//GRD
	printf("+ %d\n",w);
	fflush(stdout);
	scanf("%d%d",&x,&y);
}
int main()
{
	//freopen("a.in","r",stdin);
	int i,tag,val;
	scanf("%d",&n);
	m=n+5;
	scanf("%d%d",&a[0],&b[0]);
	//qry(0,a[0],b[0]);//GRD
	//GRD::init();//GRD
	for(i=3;i<=m;i++) pl[i]=i*(i-1)*(i-2)/6;
	for(i=m;i>=3;i--) pl[i]-=pl[i-1];
	qry(2,a[1],b[1]);
	qry(1,a[2],b[2]);
	qry(3,a[3],b[3]);
	qry(1,a[4],b[4]);
	p[2]=(b[4]-b[3])-(b[2]-b[1])-1;
	p[3]=(b[2]-b[1])/(p[2]+1);
	if(a[4]-a[3]==0) p[1]=0;
	else p[1]=qvl(a[4]-a[3])-2;
	tag=((b[3]-b[2])-(p[1]+1)*(p[2]+1)!=0);
	for(i=4;i<n;i++)
	{
		qry(i,a[i+1],b[i+1]);
		if(a[i+1]==a[i]) 
		{
			p[i]=tag;
		}
		else
		{
			p[i]=qvl(a[i+1]-a[i])-1;
		}
		tag=((b[i+1]-b[i])-(p[i-2]+1)*(p[i-1]+1)!=0);
	}
	s[1]=p[1]+2;
	for(i=2;i<n;i++) s[i]=p[i]+1;
	val=b[n];
	for(i=1;i+2<n;i++) val-=s[i]*s[i+1]*s[i+2];
	val/=s[n-2]*s[n-1];
	p[n]=val;
	printf("! ");for(i=1;i<=n;i++) printf("%d ",p[i]);
	fflush(stdout);
	return 0;
}