#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
int n,m,w,L,R,Ans;
int A[Maxn],tmp[Maxn];

inline int check(int x)
{
	int cnt=0,now=0;
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=n;i++)
	{
		if (A[i]+now<x) tmp[i]=x-(A[i]+now),cnt+=tmp[i];
		if (cnt>m) return 0;
		now+=tmp[i];
		if (i>=w) now-=tmp[i-w+1];
	}
	return cnt<=m;
}

int main()
{
	scanf("%d%d%d",&n,&m,&w);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	L=0,R=1e9+1e5+19;
	while (L<R)
	{
		int Mid=(L+R)>>1;
		if (check(Mid)) Ans=Mid,L=Mid+1;else R=Mid;
	}
	if (check(L)) Ans=L;
	printf("%d\n",Ans);
}