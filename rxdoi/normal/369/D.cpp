#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=3000+19;
struct state {int x,y;} Q[Maxn*Maxn];
int f,w,n,k,L0,L1,Ans;
int A[Maxn],Dis[Maxn][Maxn];

inline void Update(int x,int y,int D)
{
	if (x>n) x=0;
	if (y>n) y=0;
	if (D<Dis[x][y]) Dis[x][y]=D,Q[++f]=(state){x,y};
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	if (n==1) {puts("1");return 0;}
	for (L0=n;L0&&A[L0]==0;L0--);
	for (L1=n;L1&&A[L1]!=100;L1--);
	memset(Dis,60,sizeof(Dis));
	Q[++f]=(state){1,2};Dis[1][2]=0;
	while (w<f)
	{
		w++;
		int x=Q[w].x,y=Q[w].y;
		if (!x||!y||Dis[x][y]>=k) continue;
		if (A[x]!=0&&L1<=x) Update(x,y+1,Dis[x][y]+1);
		if (y<=L0&&A[x]!=100) Update(y,y+1,Dis[x][y]+1);
		if (A[x]!=0&&y<=L0) Update(y+1,y+2,Dis[x][y]+1);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) Ans+=(Dis[i][j]<=k);
	for (int i=1;i<=n;i++) Ans+=(Dis[i][0]<=k);
	Ans+=(Dis[0][0]<=k);
	printf("%d\n",Ans);
}