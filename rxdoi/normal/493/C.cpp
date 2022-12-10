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

const int N=2e5+19;
struct node
{
	int x,f;
	bool operator < (const node& B) const {return x<B.x;}
} A[2*N];
struct Sol
{
	int a,b;
	bool operator < (const Sol& B) const {return !(a-b>B.a-B.b||a-b==B.a-B.b&&a>B.a);}
} Ans;
int n,m,a,b;

int main()
{
	n=IN();For(i,1,n+1) A[i]=(node){IN(),1};
	m=IN();For(i,1,m+1) A[i+n]=(node){IN(),2};
	sort(A+1,A+n+m+1);
	Ans=(Sol){a=3*n,b=3*m};
	For(i,1,n+m+1)
	{
		if (A[i].x!=A[i-1].x) Ans=max(Ans,(Sol){a,b});
		if (A[i].f==1) a--;else b--;
	}
	Ans=max(Ans,(Sol){a,b});
	printf("%d:%d\n",Ans.a,Ans.b);
}