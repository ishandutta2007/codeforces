#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
struct Per
{
	int c,p,Dis;
	bool operator < (const Per& B) const
	{
		return p>B.p||p==B.p&&c<B.c;
	}
} A[Maxn];
int c[Maxn],p[Maxn],vis[Maxn],Out[Maxn];
int tot=0,n,k,Ans=0,Dis,Min,now,r[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&A[i].c,&A[i].p),A[i].Dis=i+1;
	scanf("%d",&k);
	for (int i=0;i<k;i++) scanf("%d",&r[i]);
	memset(Out,255,sizeof(Out));
	sort(A,A+n);
	now=k-1;
	for (int i=0;i<n;i++)
	{
		Min=2147483647;
		Dis=-1;
		for (int j=0;j<k;j++)
			if (r[j]>=A[i].c&&r[j]<Min&&!vis[j]) {Min=r[j];Dis=j;}
		if (Dis==-1) continue;
		vis[Dis]=1;
		Ans+=A[i].p;tot++;
		Out[A[i].Dis]=Dis+1;
	}
	printf("%d %d\n",tot,Ans);
	for (int i=1;i<=n;i++)
		if (Out[i]!=-1) printf("%d %d\n",i,Out[i]);
	return 0;
}