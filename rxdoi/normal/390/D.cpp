#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=53;
struct Point
{
	int x,y;
	bool operator < (const Point& B) const {return x+y<B.x+B.y;}
} A[N*N];
int n,m,f,w,k,Ans,t;

void Output(int x,int y)
{
	if (x==1&&y==1) {printf("(%d,%d) ",x,y);return;}
	if (x==1) Output(x,y-1);else Output(x-1,y);
	printf("(%d,%d) ",x,y);
}

int main()
{
	n=IN(),m=IN(),k=IN();
	For(i,1,n+1) For(j,1,m+1) A[++t]=(Point){i,j};
	sort(A+1,A+t+1);
	For(i,1,k+1) Ans+=(A[i].x-1)+(A[i].y-1)+1;
	printf("%d\n",Ans);
	for (int i=k;i;i--) Output(A[i].x,A[i].y),puts("");
}