#include<bits/stdc++.h>
#define MAXN 45
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,p,a[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&p);
	string str;
	for(ll i=0;i<n;i++)
	{
		cin>>str;
		if(str.size()==4) a[i]=0; else a[i]=1;
	}
	ll now=0,res=0;
	for(ll i=n-1;i>=0;i--)
	{
		res+=now*p+a[i]*p/2;
		now=now*2+a[i];
	}
	printf("%I64d\n",res);
	return 0;
}