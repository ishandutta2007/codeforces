#include<cstdio>
#include<cctype>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
char s[N];
int A[N],n,L,R,Q;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	For(i,1,n+1) A[i]=A[i-1]+(s[i]==s[i+1]);
	Q=IN();
	while (Q--)
	{
		L=IN(),R=IN();
		printf("%d\n",A[R-1]-A[L-1]);
	}
}