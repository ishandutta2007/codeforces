#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=4e5+50,inf=(ll)1e10;
ll n,sum,ans=0;
struct Node{ll a,t;}p[N];
bool cmp(const Node &a,const Node &b){return a.a<b.a;}
priority_queue<ll> prq;
int main()
{
	ll i,now;
	n=rd();
	for(i=1;i<=n;i++) p[i].a=rd();
	for(i=1;i<=n;i++) p[i].t=rd();
	sort(p+1,p+n+1,cmp);
	now=0;
	p[n+1].a=inf;
	for(i=1;i<=n;i++)
	{
		prq.push(p[i].t);sum+=p[i].t;
		now=p[i].a;
		while((!prq.empty())&&now+1<=p[i+1].a) 
		{
			now++;
			sum-=prq.top();prq.pop();
			ans+=sum;
		}
	}
	printf("%lld\n",ans);
	return 0;
}