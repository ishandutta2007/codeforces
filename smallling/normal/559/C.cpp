#include<cstdio>
#include<cstring>

#define mo 1000000007

using namespace std;

int f[200020],ff[200020],inv[200020];
int n,m,p,x[200020],y[200020];

int Get(int a,int b)
{
	int cnt=0,nowans=1;
	if(x[a]>x[b])return -1;
	cnt+=x[b]-x[a];
	nowans=1ll*nowans*inv[x[b]-x[a]]%mo;
	if(y[a]>y[b])return -1;
	cnt+=y[b]-y[a];
	nowans=1ll*nowans*inv[y[b]-y[a]]%mo;
	return 1ll*nowans*f[cnt]%mo;
}

int GetAns(int x)
{
	if(ff[x]!=-1)return ff[x];
	ff[x]=Get(0,x);
	for(int i=1;i<=p+1;i++)
	{
		if(i==x)continue;
		int nowans=Get(i,x);
		if(nowans!=-1)ff[x]=(ff[x]-1ll*GetAns(i)*nowans%mo+mo)%mo;
	}
	return ff[x];
}

int Pow(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%mo;
		x=1ll*x*x%mo;
		m>>=1;
	}
	return nowans;
}

int main()
{
	f[0]=1;
	for(int i=1;i<=200000;i++)f[i]=1ll*f[i-1]*i%mo;
	inv[0]=1;
	for(int i=1;i<=200000;i++)inv[i]=1ll*inv[i-1]*Pow(i,mo-2)%mo;
	scanf("%d%d%d",&n,&m,&p);
	x[p+1]=n,y[p+1]=m;
	for(int i=1;i<=p;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=p+1;i++)x[i]--,y[i]--;
	memset(ff,-1,sizeof ff);
	ff[0]=1;
	printf("%d",GetAns(p+1));
}