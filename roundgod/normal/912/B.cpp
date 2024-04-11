#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ll cnt=0,t=n;
	while(t>0)
	{
		t=t>>1;
		cnt++;
	}
	if(m>=2) printf("%I64d\n",(ll)(1LL<<cnt)-1);
	else printf("%I64d\n",n);
	return 0;
}