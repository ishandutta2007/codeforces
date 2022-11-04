#include <cstdio>
#include <algorithm>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 2e5, M = 8e5;

int t, n, m, tmp[N << 1], *tmpend, l[N], r[N], ANS;

struct node{
	int cnt;
	bool l, r;
	void set(bool x = 1){
		cnt = l = r = x;
	}
}tree[2][M << 2], ans[M << 2];
int tag[M << 2];

void add(int i){
	tree[1][i] = tree[0][i];
	tree[0][i].set();
	++tag[i];
}

void push(int i){
	if(tag[i] == 1) add(le), add(ri);
	else{
		tree[0][le].set(), tree[1][le].set();
		tree[0][ri].set(), tree[1][ri].set();
		tag[le] = tag[ri] = tag[i];
	}
	tag[i] = 0;
}

void pull(node *tree, int i){
	tree[i].l = tree[le].l;
	tree[i].r = tree[ri].r;
	tree[i].cnt = tree[le].cnt + tree[ri].cnt - (tree[le].r && tree[ri].l);
}

int L, R;
void mod(int i, int l, int r){
	if(l >= L && r <= R){
		add(i);
		return;
	}
	if(tag[i]) push(i);
	int mid = (l + r) >> 1;
	if(mid >= L) mod(le, l, mid);
	if(mid < R) mod(ri, mid + 1, r);
	pull(tree[0], i), pull(tree[1], i);
}

void get(int i, int l, int r){
	if(l >= L && r <= R){
		ans[i] = tree[1][i];
		return;
	}
	if(tag[i]) push(i);
	int mid = (l + r) >> 1;
	if(mid >= L) get(le, l, mid);
	else ans[le] = tree[0][le];
	if(mid < R) get(ri, mid + 1, r);
	else ans[ri] = tree[0][ri];
	pull(ans, i);
}

void clear(int i, int l, int r){
	tag[i] = 0;
	tree[0][i].set(0), tree[1][i].set(0);
	if(l == r) return;
	int mid = (l + r) >> 1;
	clear(le, l, mid);
	clear(ri, mid + 1, r);
}

int main(){
	scanf("%d", &t);
	while(t--){
		ANS = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d%d", l + i, r + i);
			tmp[i << 1] = l[i];
			tmp[i << 1 | 1] = r[i];
		}
		sort(tmp, tmp + (n << 1));
		tmpend = unique(tmp, tmp + (n << 1));
		m = ((tmpend - tmp) << 1) - 1;
		clear(1, 1, m);
		for(int i = 0; i < n; i++){
			l[i] = (lower_bound(tmp, tmpend, l[i]) - tmp) << 1 | 1;
			r[i] = (lower_bound(tmp, tmpend, r[i]) - tmp) << 1 | 1;
			L = l[i], R = r[i], mod(1, 1, m);
		}
		for(int i = 0; i < n; i++){
			L = l[i], R = r[i], get(1, 1, m);
			ANS = max(ANS, ans[1].cnt);
		}
		printf("%d\n", ANS);
	}
	return 0;
}