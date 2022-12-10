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

int d[100],t,w,m;

int main()
{
	w=IN(),m=IN();
	for (int i=m;i;i/=w) d[t++]=i%w;
	For(i,0,100)
	{
		if (d[i]>=w)
		{
			d[i+1]+=d[i]/w;
			d[i]%=w;
		}
		if (d[i]==0) continue;
		if (d[i]!=1&&d[i]!=w-1) return puts("NO"),0;
		if (w!=2&&d[i]==w-1) d[i+1]++;
	}
	puts("YES");
}