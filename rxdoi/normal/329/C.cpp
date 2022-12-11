#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
struct Edge{int y,nxt;} E[Maxn*2];
int A[Maxn],Last[Maxn],n,m,x,y,cnt;

inline void Add(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}

int main()
{
	srand(time(0));
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d",&x,&y),Add(x,y);
	int k=300;
	for (int i=1;i<=n;i++) A[i]=i;
	while (k--)
	{
		random_shuffle(A+1,A+n+1);
		int FFlag=1;
		for (int i=1;i<=m;i++)
		{
			int Flag=1;
			for (int j=Last[A[i]];j^-1;j=E[j].nxt)
				if (E[j].y==A[i%n+1]) {Flag=0;break;}
			if (!Flag) {FFlag=0;break;}
		}
		if (FFlag) {for (int i=1;i<=m;i++) printf("%d %d\n",A[i],A[i%n+1]);return 0;}
	}
	puts("-1");
}