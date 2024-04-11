#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll k,d,t;
int main()
{
	scanf("%I64d%I64d%I64d",&k,&d,&t);
	ll t1,t2;
	if(d>=k)
	{
		t1=k;
		t2=d-k;
	}
	else
	{
		t1=k;
		t2=(d-k%d)%d;
	}
	ll tt=2*t1+t2;
	ll p=2*t/tt,rem=2*t%tt;
	if(rem<2*t1)
	{
		printf("%f\n",(double)p*(t1+t2)+(double)rem/2);
		return 0;
	}
	else
	{
		printf("%f\n",(double)p*(t1+t2)+t1+(rem-2*t1));
		return 0;
	}
	return 0;
}