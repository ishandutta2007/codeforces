#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,x;
int main()
{
	scanf("%I64d",&t);
	for(ll i=0;i<t;i++)
	{
		bool f=true;
		ll t1=0,t2=0;
		scanf("%I64d",&x);
		if(x==0)
		{
			puts("1 1");
			continue;
		}
		for(ll j=1;;j++)
		{
			if(x>j*j) continue;
			if(4*x<j*j*3) break;
			ll res=j*j-x,divi=(ll)sqrt(res);
			if(divi*divi!=res||divi==0) continue;
			if(j/(j/divi)==divi)
			{
				t1=j;
				t2=j/divi;
				f=false;
				break;
			}
		}
		if(f) puts("-1"); else printf("%I64d %I64d\n",t1,t2);
	}
	return 0;
}