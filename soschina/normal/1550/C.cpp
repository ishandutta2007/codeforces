#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 2e5 + 1;
int t, n, m, pos, a[N], b[N];
long long ans;

struct segtree{
	int tree[N << 2], tag[N << 2], L, R, K;
	void init(){
		memset(tree + 1, 0, sizeof(int) * (m << 2));
		memset(tag + 1, 0, sizeof(int) * (m << 2));
	}
	void push(int i){
		if(tag[i]){
			tag[le] = max(tag[le], tag[i]);
			tag[ri] = max(tag[ri], tag[i]);
			tree[le] = max(tree[le], tag[i]);
			tree[ri] = max(tree[ri], tag[i]);
			tag[i] = 0;
		}
	}
	void _mod(int i, int l, int r){
		tree[i] = max(tree[i], K);
		if(L <= l && r <= R){
			tag[i] = max(tag[i], K);
			return;
		}
		push(i);
		int mid = (l + r) >> 1;
		if(mid >= L) _mod(le, l, mid);
		if(mid < R) _mod(ri, mid + 1, r);
	}
	void mod(int l, int r, int k){
		L = l, R = r, K = k;
		_mod(1, 1, m);
	}
	int _query(int i, int l, int r){
		if(L <= l && r <= R) return tree[i];
		push(i);
		int mid = (l + r) >> 1;
		if(mid >= L){
			if(mid < R) return max(_query(le, l, mid), _query(ri, mid + 1, r));
			return _query(le, l, mid); 
		}
		return _query(ri, mid + 1, r);
	}
	int query(int l, int r){
		L = l, R = r;
		return _query(1, 1, m);
	}
}treea, treeb, treec, treed;

int main(){
	scanf("%d", &t);
	while(t--){
		treea.init(), treeb.init(), treec.init(), treed.init();
		pos = 0, ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", a + i);
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		m = unique(b + 1, b + 1 + n) - b - 1;
		for(int i = 1; i <= n; i++){
			a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
			pos = max(pos, max(treeb.query(1, a[i]), treed.query(a[i], m)));
			ans += i - pos;
			int p = treea.query(1, a[i]);
			treeb.mod(a[i], m, p);
			treea.mod(a[i], m, i);
			p = treec.query(a[i], m);
			treed.mod(1, a[i], p);
			treec.mod(1, a[i], i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}