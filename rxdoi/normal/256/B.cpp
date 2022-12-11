#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
int n,x,y,c,L,R;

inline LL count(LL x) {return 1LL*x*(x+1)/2LL;}
inline int check(int t)
{
	LL Ans=-1;
	Ans+=count(t+1)*2LL;
	Ans-=count(max(x+t-n,0))+count(max(t-y+1,0))-count(max(x+t-n-y,0));
	Ans-=count(max(t-x+1,0))+count(max(y+t-n,0))-count(max(y+t-n-x,0));
	Ans+=count(max(t-1,0))*2LL;
	Ans-=count(max(t-x,0))+count(max(t-y,0))-count(max(t-x-y+1,0));
	Ans-=count(max(x+t-n-1,0))+count(max(y+t-n-1,0))-count(max(x+y-n-n+t-1,0));
	return Ans>=c;
}

int main()

{
	scanf("%d%d%d%d",&n,&x,&y,&c);
	L=-1;R=45000;
	while (L<R)
	{
		int Mid=(L+R)>>1;
		if (check(Mid)) R=Mid;else L=Mid+1;
	}
	printf("%d\n",R);
}