#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll a[14],b[14];
int main()
{
	for(ll i=0;i<14;i++)
		scanf("%I64d",&a[i]);
	ll ans=0;
	for(ll i=0;i<14;i++)
	{
		ll res=0;
		for(ll j=0;j<14;j++)
			b[j]=a[j];
		ll q=a[i]/14,r=a[i]%14;
		b[i]=0;
		for(ll j=0;j<14;j++)
			b[j]+=q;
		for(ll j=i+1;j<i+1+r;j++)
			if(j>=14) b[j-14]++; else b[j]++;
		for(ll j=0;j<14;j++)
			if(b[j]%2==0) res+=b[j];
		ans=max(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}