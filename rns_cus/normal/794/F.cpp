#include<bits/stdc++.h>
using namespace std;

#define N 400040

#define left(I) (I<<1)
#define right(I) (I<<1|1)

long long sum[N][11], tmp[11];
int u, v, L, R, a[N][11], type;
int n, q, arr[N];

void push_down(int id){
	for(int i = 0; i <= 9; i ++) tmp[i] = sum[left(id)][i], sum[left(id)][i] = 0;
	for(int i = 0; i <= 9; i ++) sum[left(id)][a[id][i]] += tmp[i];
	for(int i = 0; i <= 9; i ++) tmp[i] = sum[right(id)][i], sum[right(id)][i] = 0;
	for(int i = 0; i <= 9; i ++) sum[right(id)][a[id][i]] += tmp[i];
	for(int i = 0; i <= 9; i ++){
		a[left(id)][i] = a[id][a[left(id)][i]];
		a[right(id)][i] = a[id][a[right(id)][i]];
	}
	for(int i = 0; i <= 9; i ++) a[id][i] = i;
}

void push_up(int id){
	for(int i = 0; i <= 9; i ++){
		sum[id][i] = sum[left(id)][i] + sum[right(id)][i];
	}
}

void update(int l, int r, int id){
	if(L <= l && r <= R){
		sum[id][v] += sum[id][u]; sum[id][u] = 0;
		for(int i = 0; i <= 9; i ++) if(a[id][i] == u) a[id][i] = v;
		return;
	}
	push_down(id);
	int m = (l + r) >> 1;
	if(m >= L) update(l, m, left(id));
	if(m < R) update(m + 1, r, right(id));
	push_up(id);
}

void build(int l, int r, int id){
	for(int i = 0; i <= 9; i ++) a[id][i] = i;
	if(l == r){
		int tmp = 1, x = arr[l];
		while(x){
			sum[id][x % 10] += tmp;
			x /= 10;
			tmp *= 10;
		}
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, left(id));
	build(m + 1, r, right(id));
	push_up(id);
}

long long query_sum(int l, int r, int id){
	long long ret = 0;
	if(L <= l && r <= R){
		for(int i = 0; i <= 9; i ++) ret += sum[id][i] * i;
		return ret;
	}
	push_down(id);
	int m = (l + r) >> 1;
	if(m >= L) ret += query_sum(l, m, left(id));
	if(m < R) ret += query_sum(m + 1, r, right(id));
	return ret;
}


int main(){
//	freopen("f.in", "r", stdin);
	scanf("%d %d",  &n, &q);
	for(int i = 1; i <= n; i ++){
		scanf("%d", arr + i);
	}
	build(1, n, 1);
	while(q --){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d %d %d %d", &L, &R, &u, &v);
			if(u == v) continue;
			update(1, n, 1);
		}
		else{
			scanf("%d %d", &L, &R);
			printf("%I64d\n", query_sum(1, n, 1));
		}
	}
}