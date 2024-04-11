#include <bits/stdc++.h>

using ll = long long;

const int max_N = 2e5 + 21;

int n,m,w,x[max_N],v[max_N];

struct frac{
	int p,q;
	frac(int p=0,int q=1){
		if(p < 0) p = -p;
		if(q < 0) q = -q;
		this->p = p;
		this->q = q;
	}
	bool operator < (const frac&o) const{
		return 1ll * p * o.q < 1ll * o.p * q;
	}
	bool operator == (const frac&o) const{
		return 1ll * p * o.q == 1ll * o.p * q;
	}
};

frac l[max_N],r[max_N],h[max_N];

int rk(const frac&o){
	return std::lower_bound(h + 1, h + 1 + m, o) - h;
}

std::vector<int>vec[max_N];

struct node{
	int siz;
	node* ch[2];
}pool[max_N * 20];

node* tail = pool;

node* rt[max_N];

void update(node*&x,node* y,int l,int r,int pos){
	x = tail ++; if (y) *x = *y; x -> siz ++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(x -> ch[0], y? y -> ch[0]: 0, l, mid, pos);
	else update(x -> ch[1], y? y -> ch[1]: 0, mid + 1, r, pos);
}

int query(node* x,int l,int r,int ql,int qr){
	if(!x || ql > qr) return 0;
	if(ql <= l && r <= qr) return x -> siz;
	int mid = (l + r) >> 1;
	int res = 0;
	if(ql <= mid) res += query(x -> ch[0], l, mid, ql, qr);
	if(qr > mid)  res += query(x -> ch[1], mid + 1, r, ql, qr);
	return res;
}

int query(int l,int r,int ql,int qr){
	if (l > r) return 0;
	int res = 0;
	res += query(rt[r], 1, m, ql, qr);
	res -= query(rt[l - 1], 1, m, ql, qr);
	return res;
}

int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i){
		scanf("%d%d",x+i,v+i);
		h[++m] = l[i] = frac(x[i], v[i] - w);	
		h[++m] = r[i] = frac(x[i], v[i] + w);
	}
	std::sort(h + 1, h + 1 + m);
	m = std::unique(h + 1 , h + 1 + m) - h - 1;
	for(int i=1;i<=n;++i)
		vec[rk(l[i])].push_back(rk(r[i]));
	for(int i=1;i<=m;++i){
		rt[i] = rt[i - 1];
		for(auto&x:vec[i]){
			update(rt[i],rt[i],1,m,x);	
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;++i){
		ans += n - 1;
		ans -= query(1, rk(l[i]) - 1, 1, rk(r[i]) - 1);
		ans -= query(rk(l[i]) + 1, m, rk(r[i]) + 1, m);
	}
	ans >>= 1;
	printf("%lld\n",ans);
	return 0;
}