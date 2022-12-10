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
int S[N],n,k,Min=(1<<30)-1,Ans;

int main()
{
	n=IN(),k=IN();
	For(i,0,n) S[i%k]+=IN();
	For(i,0,k) if (S[i]<Min) Min=S[i],Ans=i+1;
	printf("%d\n",Ans);
}