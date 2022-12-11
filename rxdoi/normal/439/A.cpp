#include<cstdio>
using namespace std;

const int Maxn=100+19;
int d,x,n,sum;

int main()
{
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf("%d",&x),sum+=x;
	if (sum+(n-1)*10<=d) printf("%d\n",(n-1)*2+(d-sum-(n-1)*10)/5);
		else printf("-1\n");
}