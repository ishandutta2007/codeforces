#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int b,k,a[100050],ans;
const int mod=2;

int main()
{
	scanf("%d%d",&b,&k);
	rep(i,1,k) scanf("%d",a+i);
	int p=1;
	repd(i,k,1) ans=(ans+a[i]*p)%mod,p=p*b%mod;
	if(ans&1) puts("odd");
	else puts("even");
	return 0;
}