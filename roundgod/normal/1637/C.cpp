#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str;
vector<int> odd;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==3&&(a[2]&1)) {puts("-1"); continue;}
		bool f=false;
		for(int i=2;i<=n-1;i++) if(a[i]!=1) f=true;
		if(!f) {puts("-1"); continue;}
		ll ans=0;
		for(int i=2;i<=n-1;i++) ans+=(a[i]+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}