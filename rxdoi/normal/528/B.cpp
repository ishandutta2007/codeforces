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
struct Seg
{
	int x,w;
	bool operator < (const Seg& B) const {return x+w<B.x+B.w;}
} A[N];
int n,Last=1,Ans=1;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=(Seg){IN(),IN()};
	sort(A+1,A+n+1);
	For(i,2,n+1)
		if (A[i].x-A[i].w>=A[Last].x+A[Last].w) Ans++,Last=i;
	printf("%d\n",Ans);
}