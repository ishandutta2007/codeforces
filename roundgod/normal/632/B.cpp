#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN];
string str;
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	cin>>str;
	ll ans=0;
	for(ll i=0;i<n;i++)
		if(str[i]=='B') ans+=a[i];
	ll res=0,cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(str[i]=='A') cnt+=a[i]; else cnt-=a[i];
		res=max(res,cnt);
	}
	cnt=0;
	for(ll i=n-1;i>=0;i--)
	{
		if(str[i]=='A') cnt+=a[i]; else cnt-=a[i];
		res=max(res,cnt);
	}
	printf("%I64d\n",res+ans);
	return 0;
}