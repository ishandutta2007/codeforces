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

long long Ans,d[15],t,tmp,pre,n;

int main()
{
	n=IN();
	for (int i=n;i;i/=10) d[t++]=i%10;
	reverse(d,d+t);
	For(i,1,t)
	{
		pre=tmp;tmp=tmp*10+9;
		Ans+=1LL*(tmp-pre)*i;
	}
	Ans+=1LL*(n-tmp)*t;
	printf("%I64d\n",Ans);
}