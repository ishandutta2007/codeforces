#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000000,top=100000;
int A[N],B[N],Al,Ar,Bl,Br,n,Ans,End,win,k;

int main()
{
	Al=Bl=N/2,Ar=Br=N/2-1;
	scanf("%d",&n);
	scanf("%d",&k);For(i,1,k+1) scanf("%d",&A[--Al]);
	scanf("%d",&k);For(i,1,k+1) scanf("%d",&B[--Bl]);
	for (Ans=1;Ans<=top;Ans++)
	{
		if (A[Ar]>B[Br]) A[--Al]=B[Br--],A[--Al]=A[Ar--];
			else B[--Bl]=A[Ar--],B[--Bl]=B[Br--];
		if (Al>Ar||Bl>Br) {End=1;win=Bl>Br?1:2;break;}
	}
	if (End) printf("%d %d\n",Ans,win);else puts("-1");
}