#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
LL n,m,k,Ans;

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if (k>n-1+m-1) {printf("-1\n");return 0;}
	LL H,L;
	if (n-1>=k) H=k,L=0;else H=n-1,L=k-(n-1);
	if (1LL*n/(H+1)*m/(L+1)>Ans) Ans=1LL*n/(H+1)*m/(L+1);
	swap(n,m);
	if (n-1>=k) H=k,L=0;else H=n-1,L=k-(n-1);
	if (1LL*n/(H+1)*m/(L+1)>Ans) Ans=1LL*n/(H+1)*m/(L+1);
	printf("%I64d\n",Ans);
}