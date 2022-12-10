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

int n,t,c,S,p,T,M;

int main()
{
	n=IN();
	while (n--) t=IN(),M=max(M,S=max(S-(t-p),0)+IN()),p=t;
	printf("%d %d\n",p+S,M);
}