#include<queue>
#include<cstdio>
using namespace std;

const int Maxk=1000000+19,N=1000+19;
typedef long long LL;
int n,m,k,p,A[N][N];
LL H[Maxk],L[Maxk],Ans=-(1LL<<60);

priority_queue<int> Q_H,Q_L;

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) scanf("%d",&A[i][j]);
	for (int i=0;i<n;i++)
	{
		int tmp=0;for (int j=0;j<m;j++) tmp+=A[i][j];Q_H.push(tmp);
	}
	for (int j=0;j<m;j++)
	{
		int tmp=0;for (int i=0;i<n;i++) tmp+=A[i][j];Q_L.push(tmp);
	}
	for (int i=1;i<=k;i++)
	{
		LL x=Q_H.top();Q_H.pop();H[i]=H[i-1]+x;Q_H.push(x-p*m);
	}
	for (int i=1;i<=k;i++)
	{
		LL x=Q_L.top();Q_L.pop();L[i]=L[i-1]+x;Q_L.push(x-p*n);
	}
	for (int cntL=0;cntL<=k;cntL++) Ans=max(Ans,H[cntL]+L[k-cntL]-1LL*(k-cntL)*cntL*p);
	printf("%I64d\n",Ans);
}