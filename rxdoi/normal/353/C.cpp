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

const int N=1e5+19;
int S[N],A[N],Ans,cur,n;
char s[N];

int main()
{
	n=IN();
	For(i,1,n+1) S[i]=S[i-1]+(A[i]=IN());
	scanf("%s",s+1);
	for (int i=strlen(s+1);i;i--)
		if (s[i]=='1') Ans=max(Ans,cur+max(A[i],S[i-1])),cur+=A[i];
	printf("%d\n",Ans);
}