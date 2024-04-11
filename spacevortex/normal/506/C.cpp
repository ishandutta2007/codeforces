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
const ll N=1e5+50,M=5050,inf=(ll)1e15;
ll n,m,K,P;
ll h[N],a[N],val[M];
bool solve(ll W)
{
	ll tot=0,C,der,i,t,w,now;
	memset(val,0,sizeof(val));
	for(i=1;i<=n;i++)
	{
		w=h[i]+m*a[i]-W;
		if(w<=0) continue;
		C=(w-1)/P+1;
		if(tot+C>m*K) return 0;
		tot+=C;der=C*P-w;
		for(t=1;t<=C;t++)
		{
			w=t*P-der-h[i];
			if(w<=0) val[0]++;
			else val[(w-1)/a[i]+1]++;
		}
	}
	if(val[m]) return 0;
	now=0;
	for(i=0;i<m;i++)
	{
		now+=val[i];now=max(now-K,0ll);
	}
	return now==0;
}
int main()
{
	ll i,sl,sr,mid;
	n=rd();m=rd();K=rd();P=rd();
	for(i=1;i<=n;i++)
	{
		h[i]=rd();a[i]=rd();
	}
	sl=0;sr=inf;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		if(solve(mid)==1) sr=mid;
		else sl=mid+1;
	}
	printf("%lld",sl);
	return 0;
}