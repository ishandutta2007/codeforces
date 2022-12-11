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

const int N=3000+19;
int A[N],B[N],n,m,cur,Ans;

int main()
{
	n=IN(),m=IN();
	For(i,0,n) A[i]=IN();
	For(i,0,m) B[i]=IN();
	sort(A,A+n);sort(B,B+m);cur=m-1;
	for (int i=n-1;~i;i--) if (cur>=0&&B[cur]>=A[i]) cur--;else Ans++;
	printf("%d\n",Ans);
}