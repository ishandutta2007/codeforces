#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long LL;
typedef double Db;

const int N=500000+19;
int A[N],B[N],C[N];
int n,Ans;

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,2,n) B[i]=(A[i-1]!=A[i]&&A[i]!=A[i+1])?B[i-1]+1:0;
	
	memcpy(C,A,sizeof(C));
	For(i,2,n) if (B[i]&&!B[i+1])
	{
		Ans=max(Ans,(B[i]+1)/2);
		int L=i-B[i]+1;
		if (B[i]&1) For(j,L,i+1) C[j]=A[L-1];else
		{
			For(j,L,L+B[i]/2) C[j]=A[L-1];
			For(j,i-B[i]/2+1,i+1) C[j]=A[i+1];
		}
	}
	
	printf("%d\n",Ans);
	For(i,1,n+1) printf("%d ",C[i]);puts("");
}