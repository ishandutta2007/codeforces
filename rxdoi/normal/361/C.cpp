#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=5000+19,oo=1e9;
struct Oper
{
	int type,L,R,x;
} B[Maxn];
int A[Maxn],C[Maxn],n,m,t;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d%d",&B[i].type,&B[i].L,&B[i].R,&B[i].x);
	for (int i=1;i<=n;i++)
	{
		int Delta=0,Max=oo;
		for (int j=0;j<m;j++)
		{
			if (B[j].type==1&&i>=B[j].L&&i<=B[j].R) Delta+=B[j].x;
			if (B[j].type==2&&i>=B[j].L&&i<=B[j].R) Max=min(Max,B[j].x-Delta);
		}
		A[i]=Max;
	}
	memcpy(C,A,sizeof(A));
	for (int i=0;i<m;i++)
	{
		if (B[i].type==1) for (int j=B[i].L;j<=B[i].R;j++) C[j]+=B[i].x;
			else
			{
				int Max=-oo;
				for (int j=B[i].L;j<=B[i].R;j++) Max=max(Max,C[j]);
				if (Max^B[i].x) {puts("NO");return 0;}
			}
	}
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d ",A[i]);printf("\n");
}