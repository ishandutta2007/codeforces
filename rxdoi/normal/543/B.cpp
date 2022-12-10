#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=3000+19,oo=1<<28;
struct Edge {int y,nxt;} E[N*2];
int Last[N],D[N][N],Q[N],cnt;
int n,m,x,y,z,S1,T1,L1,S2,T2,L2,t1,t2,Ans;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void BFS(int S,int *D)
{
	For(i,1,n+1) D[i]=oo;D[S]=0;
	int f=1,w=0;Q[1]=S;
	while (f>w)
	{
		int x=Q[++w];
		for (int i=Last[x];~i;i=E[i].nxt)
			if (D[E[i].y]==oo) D[E[i].y]=D[x]+1,Q[++f]=E[i].y;
	}
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	For(i,0,m) scanf("%d%d",&x,&y),Link(x,y);
	scanf("%d%d%d",&S1,&T1,&L1);
	scanf("%d%d%d",&S2,&T2,&L2);
	For(i,1,n+1) BFS(i,D[i]);
	if (D[S1][T1]<=L1&&D[S2][T2]<=L2) Ans=D[S1][T1]+D[S2][T2];else Ans=oo+1;
	For(i,1,n+1) For(j,1,n+1)
		if ((t1=D[S1][i]+D[i][j]+D[j][T1])<=L1)
		{
			if ((t2=D[S2][i]+D[i][j]+D[j][T2])<=L2) Ans=min(Ans,t1+t2-D[i][j]);
			if ((t2=D[T2][i]+D[i][j]+D[j][S2])<=L2) Ans=min(Ans,t1+t2-D[i][j]);
		}
	printf("%d\n",Ans>oo?-1:m-Ans);
}