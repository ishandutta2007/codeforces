#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll N = 1e6+10;

ll n,m,p,top;
struct zs{
	ll x,v;
}d[N],b[N],q[N];
struct hzw{
	ll b,d,v;
}c[N];
struct cyb{
	ll l,r,mid,maxn,tag;
}a[N << 2];

inline ll cmp(zs x,zs y){
	return x.x < y.x || (x.x == y.x && x.v < y.v);
}

inline ll cmpp(hzw x,hzw y){
	return x.b < y.b || (x.b == y.b && x.d < y.d);
}

inline void build(ll num,ll l,ll r){
	a[num].l = l;
	a[num].r = r;
	a[num].mid = (l+r) >> 1;
	if(l < r){
		build(num<<1,l,a[num].mid);
		build(num<<1|1,a[num].mid+1,r);
	}
}

inline void add(ll num,ll x,ll v){
	if(a[num].l >= x){
		a[num].maxn += v;
		a[num].tag += v;
		return;
	}
	a[num<<1].maxn += a[num].tag;
	a[num<<1].tag += a[num].tag;
	a[num<<1|1].maxn += a[num].tag;
	a[num<<1|1].tag += a[num].tag;
	a[num].tag = 0;
	add(num<<1|1,x,v);
	if(a[num].mid >= x)
		add(num<<1,x,v);
	a[num].maxn = max(a[num<<1].maxn,a[num<<1|1].maxn);
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&p);
	for(ll i=1;i <= n;i++)
		scanf("%lld%lld",&b[i].x,&b[i].v);
	for(ll i=1;i <= m;i++)
		scanf("%lld%lld",&d[i].x,&d[i].v);
	for(ll i=1;i <= p;i++)
		scanf("%lld%lld%lld",&c[i].b,&c[i].d,&c[i].v);
	build(1,0,1000000);
	sort(b+1,b+1+n,cmp);
	sort(d+1,d+1+m,cmp);
	sort(c+1,c+1+p,cmpp);
	for(ll i=1;i <= n;i++){
		while(top > 0 && (b[i].v <= q[top].v))
			top--;
		q[++top] = b[i];
	}
	memcpy(b,q,sizeof(q));
	n = top;
	top = 0;
	for(ll i=1;i <= m;i++){
		while(top > 0 && (d[i].v <= q[top].v))
			top--;
		q[++top] = d[i];
	}
	memcpy(d,q,sizeof(q));
	m = top;
	top = 1;
	for(ll i=1;i <= m;i++)
		add(1,d[i-1].x,d[i-1].v-d[i].v);
	add(1,d[m].x,-(long long)1e18);	//!!!!!
	ll ans = -(long long)1e18;
	for(ll i=1;i <= n;i++){
		while(c[top].b < b[i].x && top <= p)
			add(1,c[top].d,c[top].v) , top++;
		ans = max(ans,a[1].maxn-b[i].v);
//		cout<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}