#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;

ll n,c[500050],l[500050],r[500050],ans,p;
struct zs{
	ll x,w;
	zs(ll xx,ll ww){
		x = xx , w = ww;
	}
};
stack<zs>q;

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i <= n;i++)
		scanf("%lld",&c[i]);
	q.push(zs(0,0));
	for(ll i=1;i <= n;i++){
		while(q.top().w > c[i]) q.pop();
		l[i] = l[q.top().x] + c[i]*(i-q.top().x);
		q.push(zs(i,c[i]));
	}
	while(!q.empty()) q.pop();
	q.push(zs(n+1,0));
	for(ll i=n;i >= 1;i--){
		while(q.top().w > c[i]) q.pop();
		r[i] = r[q.top().x] + c[i]*(q.top().x-i);
		q.push(zs(i,c[i]));
	}
	for(ll i=1;i < n;i++)
		if(l[i]+r[i+1] > ans)
			ans = l[i]+r[i+1] , p = i;
	ll v = c[p];
	for(ll i=p;i >= 1;i--)
		c[i] = min(c[i],v) , v = min(v,c[i]);
	v = c[p+1];
	for(ll i=p+1;i <= n;i++)
		c[i] = min(c[i],v) , v = min(v,c[i]);
	for(ll i=1;i <= n;i++)
		printf("%lld ",c[i]);
	puts("");
	return 0;
}