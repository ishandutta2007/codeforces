#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
LL n;LL ans=0;
void check(LL ab,LL bc,LL ac)
{
	if((ab+bc+ac)%2==1)return;
	LL abc=(ab+bc+ac)/2;
	LL a=ab+ac-abc;
	LL b=ab+bc-abc;
	LL c=bc+ac-abc;
	if(a<=0||b<=0||c<=0)return;
	if(a==b&&b==c)
	{
		ans++;return;
	}
	if(a==b||b==c||a==c)
	{
		ans+=3;return;
	}
	ans+=6;
}
int main()
{
	scanf("%I64d",&n);
	if(n%3!=0)
	{
		printf("0\n");
		return 0;
	}
	n/=3;
	for(LL a=1;a*a*a<=n;a++)
	if(n%a==0)
	{
	for(LL b=(LL)sqrt(n/a);b>=a;b--)
	if((n/a)%b==0)
	{
		LL c=(n/b)/a;
		if(a+b<=c)break;
		if(c>=b)
		check(a,b,c);
	}
	}
	printf("%I64d\n",ans);
	return 0;
}