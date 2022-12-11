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

const int N=1e5+19;
struct Tree {int x,h;} A[N];
int n,cnt,R;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=(Tree){IN(),IN()};
	cnt++,R=A[1].x;
	A[n+1].x=2147483647;
	For(i,2,n+1)
		if (R<A[i].x-A[i].h) cnt++,R=A[i].x;
			else if (A[i].x+A[i].h<A[i+1].x) cnt++,R=A[i].x+A[i].h;
				else R=A[i].x;
	printf("%d\n",cnt);
}