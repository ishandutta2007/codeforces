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

int n,Ans;

int main()
{
	for (n=IN();n--;) Ans+=(IN()+IN()+IN())>=2;
	printf("%d\n",Ans);
}