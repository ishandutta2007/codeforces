#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD1 1000000007
#define MOD2 1000000009
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,t;
struct node
{
	ll hash,pre,len;
}a[MAXN];
char str[MAXN];
bool cmp(node x,node y)
{
	return x.len>y.len;
}
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		ll tt=0;
		scanf("%I64d",&n);
		set<ll> s;
		for(ll i=0;i<n;++i)
		{
			scanf("%s",str);
			ll len=strlen(str);
			ll s1=0,s2=0,s3=0,s4=0;
			for(ll j=0;j<len;j++)
			{
				s1=(s1*97+str[j])%MOD1;
				s2=(s2*97+str[j])%MOD2;
				if(j>0) 
				{
					s3=(s3*97+str[j])%MOD1;
				 	s4=(s4*97+str[j])%MOD2;
				 	a[tt].pre=s3*MOD1+s4;
				}
				else a[tt].pre=-1;
				a[tt].hash=s1*MOD1+s2;
				s.insert(a[tt].hash);
				a[tt].len=j;
				tt++;
			}
		}
		sort(a,a+tt,cmp);
		for(ll i=0;i<tt;i++)
			if(s.count(a[i].hash)) s.erase(a[i].pre);
		printf("%d\n",s.size());
	}
	return 0;
}