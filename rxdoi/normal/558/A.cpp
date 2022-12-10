#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100+19;
struct Tree
{
	int x,A;
} S[N],T[N];
int n,Ans,C1,C2,x,A;

bool cmp1(Tree A,Tree B) {return A.x<B.x;}
bool cmp2(Tree A,Tree B) {return A.x>B.x;}

int main()
{
	scanf("%d",&n);
	For(i,1,n+1)
	{
		scanf("%d%d",&x,&A);
		if (x<0) S[C1++]=(Tree){x,A};else T[C2++]=(Tree){x,A};
	}
	sort(S,S+C1,cmp2);
	sort(T,T+C2,cmp1);
	For(i,0,min(C1,C2)) Ans+=S[i].A+T[i].A;
	if (C1>C2) Ans+=S[C2].A;
	if (C2>C1) Ans+=T[C1].A;
	printf("%d\n",Ans);
}