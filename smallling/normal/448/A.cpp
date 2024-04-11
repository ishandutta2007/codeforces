#include<cstdio>

using namespace std;

int a1,a2,a3,b1,b2,b3,n,ans;

int main()
{
	scanf("%d%d%d",&a1,&a2,&a3);
	scanf("%d%d%d",&b1,&b2,&b3);
	ans=(a1+a2+a3)/5+(((a1+a2+a3)%5)!=0);
	ans+=(b1+b2+b3)/10+(((b1+b2+b3)%10)!=0);
	scanf("%d",&n);
	if(n>=ans)puts("YES");
	else puts("NO");
}