#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5+10;

int n,t,c[N],v[N];
struct osc{
	int l,r,mid,minn,x,sum,tag;
}a[N << 2];
struct lwn{
	int l,r,num;
}q[N];

inline int cmp(lwn x,lwn y){
	return x.l < y.l || (x.l == y.l && x.r < y.r);
}

inline void build(int num,int l,int r){
	a[num].l = l , a[num].r = r , a[num].mid = (l+r) >> 1;
	if(l < r){ 
		build(num<<1,l,a[num].mid) , build(num<<1|1,a[num].mid+1,r);
		if(a[num<<1].minn < a[num<<1|1].minn)
			a[num].minn = a[num<<1].minn , a[num].x = a[num<<1].x;
		else
			a[num].minn = a[num<<1|1].minn , a[num].x = a[num<<1|1].x;
		a[num].sum = a[num<<1].sum + a[num<<1|1].sum;
	}
	else a[num].minn = c[l] , a[num].x = l , a[num].sum = c[l] < 1e9 ? 1 : 0;
}

inline int query(int num,int l,int r){
	if(a[num].l >= l && a[num].r <= r)
		return a[num].sum;
	a[num<<1].tag += a[num].tag , a[num<<1|1].tag += a[num].tag;
	a[num<<1].minn -= a[num].tag , a[num<<1|1].minn -= a[num].tag;
	a[num].tag = 0;
	int ans = 0;
	if(a[num].mid >= l) ans += query(num<<1,l,r);
	if(a[num].mid < r) ans += query(num<<1|1,l,r);
	return ans;
}

inline void add(int num,int l,int r,int v){
	if(a[num].l >= l && a[num].r <= r){
		a[num].minn += v;
		a[num].tag -= v;
		if(v != -1) a[num].sum = 0;
		return;
	}
	
	a[num<<1].tag += a[num].tag , a[num<<1|1].tag += a[num].tag;
	a[num<<1].minn -= a[num].tag , a[num<<1|1].minn -= a[num].tag;
	a[num].tag = 0;
	
	if(a[num].mid >= l) add(num<<1,l,r,v);
	if(a[num].mid < r) add(num<<1|1,l,r,v);
	
	if(a[num<<1].minn < a[num<<1|1].minn)
		a[num].minn = a[num<<1].minn , a[num].x = a[num<<1].x;
	else
		a[num].minn = a[num<<1|1].minn , a[num].x = a[num<<1|1].x;
	a[num].sum = a[num<<1].sum + a[num<<1|1].sum;
}

inline void del(int x){
	add(1,x,x,2e9) , add(1,x,n,-1);
	while(a[1].minn < 0){
		int xx = a[1].x;
		add(1,xx,xx,2e9) , add(1,xx,n,-1);
	}
}

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]);
	int cnt = 0;
	for(int i=1;i <= n;i++){
		if(c[i] <= i && c[i] >= i-cnt) c[i] = cnt-(i-c[i]) , cnt++;
		else c[i] = 2e9;
	}
	for(int i=1;i <= t;i++) scanf("%d%d",&q[i].l,&q[i].r) , q[i].num = i;
	sort(q+1,q+1+t,cmp);
	build(1,1,n);
	int cur = 0;
	for(int i=1;i <= t;i++){
		while(cur < q[i].l){
			cur++;
			if(query(1,cur,cur))
				del(cur);
		}
		v[q[i].num] = query(1,q[i].l+1,n-q[i].r);
	}
	for(int i=1;i <= t;i++) printf("%d\n",v[i]);
	return 0;
}