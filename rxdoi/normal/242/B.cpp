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

int SL=(1<<30)-1,SR,BR=-1,n,L,R,ID;

int main()
{
	n=IN();
	For(i,1,n+1)
	{
		L=IN(),R=IN();
		if (R>BR) BR=R;
		if (L<SL||L==SL&&R>SR) SL=L,SR=R,ID=i;
	}
	printf("%d\n",SR>=BR?ID:-1);
}