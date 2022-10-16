#include <cstdio>
using namespace std;
const int mod=998244353;
int w,h;
int fpw(int b,int e)
{
	if (e==0)
		return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1)
		ret=1ll*ret*b%mod;
	return ret;
}
int main()
{
	scanf("%d%d",&w,&h);
	printf("%d\n",fpw(2,w+h));
	return 0;
}