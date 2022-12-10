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
int A[N],S[11][N],Fa[N],n,k,w,L,R,Ans;
char s[N];

int main()
{
	n=IN(),k=IN(),w=IN();
	scanf("%s",s+1);
	For(i,0,k+1) For(j,1,n+1) S[i][j]=S[i][j-1]+(s[j]=='0'&&j%k==i||s[j]=='1'&&j%k!=i);
	while (w--)
	{
		L=IN(),R=IN();
		printf("%d\n",S[(L-1)%k][R]-S[(L-1)%k][L-1]);
	}
}