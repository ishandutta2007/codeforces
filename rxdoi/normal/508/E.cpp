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

const int N=600+19;
struct Query {int L,R;} A[N];
int S[N],Ans[2*N],Len[N],top,n;

int main()
{
	n=IN();
	For(i,0,n) A[i]=(Query){IN(),IN()};
	for (int i=n-1;~i;i--)
	{
		int x=1;
		while (top&&!(A[i].L<=x&&x<=A[i].R)) x+=S[top--];
		if (!(A[i].L<=x&&x<=A[i].R)) return puts("IMPOSSIBLE"),0;
		S[++top]=x+1,Len[i]=x;
	}
	for (int i=0,j=0;i<n;i++) {while (Ans[j]) j++;Ans[j+Len[i]]=1;j++;}
	For(i,0,2*n) putchar("()"[Ans[i]]);
	puts("");
}