#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=200000+19;
int A[N],n;

int main()
{
	n=IN();
	For(i,0,n) A[i]=IN()+i;
	sort(A,A+n);
	For(i,0,n) A[i]-=i;
	For(i,0,n) if (A[i]<0) return puts(":("),0;
	For(i,0,n-1) if (A[i]>A[i+1]) return puts(":("),0;
	For(i,0,n) printf("%d ",A[i]);puts("");
}