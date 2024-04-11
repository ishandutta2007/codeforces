#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define	n	10005
#define INF	(1ll<<50)
#define I64	long long
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)

int		N,X,B[n],L[n],R[n];
I64		G[n],F[2][n];

int		main(){
		scanf("%d%d",&N,&X);B[++*B]=X;
		For(i,1,N)	scanf("%d%d",&L[i],&R[i]),B[++*B]=L[i],B[++*B]=R[i];
		sort(B+1,B+*B+1);	*B=unique(B+1,B+*B+1)-B-1;

		X=lower_bound(B+1,B+*B+1,X)-B;
		For(i,1,N)	L[i]=lower_bound(B+1,B+*B+1,L[i])-B,
					R[i]=lower_bound(B+1,B+*B+1,R[i])-B;

		For(i,1,*B)	F[0][i]=INF;	F[0][X]=0;
		For(k,1,N)	{
			int p=k&1,q=p^1;	G[0]=G[(*B)+1]=INF;
			For(i,1,*B)	G[i]=min(G[i-1],F[q][i]-B[i]);
			For(i,1,*B)	F[p][i]=G[i]+B[i];
			Rep(i,*B,1)	G[i]=min(G[i+1],F[q][i]+B[i]);
			For(i,1,*B)	F[p][i]=min(F[p][i],G[i]-B[i]);

			For(i,1,*B)	{
				if	(i<=L[k])	F[p][i]+=B[L[k]]-B[i];
				if	(i>=R[k])	F[p][i]+=B[i]-B[R[k]];
			}
		}

		I64	Ans=INF;
		For(i,1,*B)	Ans=min(Ans,F[N&1][i]);
		printf("%I64d\n",Ans);
}