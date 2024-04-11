#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll a,b,x,y,z;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	scanf("%I64d%I64d%I64d",&x,&y,&z);
	printf("%I64d\n",max((ll)0,x*2+y-a)+max((ll)0,y+3*z-b));
	return 0;
}