#include<cstdio>
using namespace std;

typedef long long LL;
int n,x,y,tmp;
LL L,R;

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	while (n--)
	{
		scanf("%d",&tmp);
		L=0,R=1e15+1;
		while (L<R)
		{
			LL Mid=(L+R)>>1;
			if (Mid/y+Mid/x>=tmp) R=Mid;else L=Mid+1;
		}
		printf("%s\n",(R%y?"Vova":(R%x?"Vanya":"Both")));
	}
}