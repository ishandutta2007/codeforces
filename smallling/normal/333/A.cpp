#include<cstdio> 

using namespace std;

long long n,now;

int main()
{
	scanf("%I64d",&n);
	now=3;
	while(n%now==0)now*=3ll;
	printf("%I64d",n/now+1);
}