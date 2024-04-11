#include<cstdio>
#include<string>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=2e5+19;
int A[N],B[N],x,n;
long long Sa,Sb;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&x);
		if (x>0) A[++*A]=x,Sa+=x;else B[++*B]=-x,Sb-=x;
	}
	if (Sa!=Sb) puts(Sa<Sb?"second":"first");
		else
		{
			For(i,1,max(*A,*B)+1) if (A[i]!=B[i]) return puts(A[i]<B[i]?"second":"first"),0;
			puts(x<0?"second":"first");
		}
}