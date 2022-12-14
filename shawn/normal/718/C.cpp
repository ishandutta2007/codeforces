#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7 , maxn = 1e5 + 10;

int n , m , A[maxn];

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

struct Martix {
	int a[2][2];
	
	Martix(){ memset(a , 0 , sizeof a); }
	
	void init () {
		for (int i = 0 ; i < 2 ; i ++)
			for (int j = 0 ; j < 2 ; j ++) 
				a[i][j] = (i == j);
	}
	
	Martix operator + (const Martix &B) const {
		Martix C;
		for (int i = 0 ; i < 2 ; i ++)
			for (int j = 0 ; j < 2 ; j ++)
				C.a[i][j] = (a[i][j] + B.a[i][j]) % MOD;
		return C;
	}
	
	Martix operator * (const Martix &B) const {
		Martix C;
		for (int i = 0 ; i < 2 ; i ++)
			for (int k = 0 ; k < 2 ; k ++)
				for (int j = 0 ; j < 2 ; j ++) 
					C.a[i][j] = (C.a[i][j] + 1ll * a[i][k] * B.a[k][j]) % MOD;
		return C;
	}
	
	Martix operator ^ (const int t) const {
		Martix A = (*this) , C;
		C.init();
		int p = t;
		while (p) {
			if (p & 1) C = C * A;
			A = A * A;
			p >>= 1;
		}
		return C;		
	}
	
}f;

struct tree{
	int l , r;
	Martix sum , lazy;
}t[maxn << 2];

void pushup(int k) {
	t[k].sum = t[k << 1].sum + t[k << 1 | 1].sum;
}

void build(int k , int l , int r) {
	t[k].l = l , t[k].r = r;
	t[k].lazy.init();
	if (l == r) {
		t[k].sum = f ^ (A[l] - 1);
		return;
	} 
	int mid = l + r >> 1;
	build(k << 1 , l , mid);
	build(k << 1 | 1 , mid + 1 , r);
	pushup(k);
}

void init() {
	f.a[0][0] = f.a[0][1] = f.a[1][0] = 1;
	f.a[1][1] = 0;
}

void pushdown(int k) {
	if (t[k].lazy.a[0][0] || t[k].lazy.a[1][1]) {
		Martix v = t[k].lazy;
		t[k << 1].lazy = v * t[k << 1].lazy;
		t[k << 1 | 1].lazy = v * t[k << 1 | 1].lazy;
		t[k << 1].sum = v * t[k << 1].sum;
		t[k << 1 | 1].sum = v * t[k << 1 | 1].sum;
		t[k].lazy.init();
	}
}

void update(int k , int x , int y , Martix v) {
	int l = t[k].l , r = t[k].r;
	if (x == l && r == y) {
		t[k].lazy = t[k].lazy * v;
		t[k].sum = t[k].sum * v; 
		return;
	} 
	pushdown(k);
	int mid = l + r >> 1;
	if (y <= mid) update(k << 1 , x , y , v);
	else if (x > mid) update(k << 1 | 1 , x , y , v);
	else update(k << 1 , x , mid , v) , update(k << 1 | 1 , mid + 1 , y , v);
	pushup(k);
}

long long query(int k , int x , int y) {
	int l = t[k].l , r = t[k].r;
	if (x == l && r == y) return (t[k].sum.a[0][0]) % MOD;
	int mid = l + r >> 1;
	pushdown(k);
	if (y <= mid) return query(k << 1 , x , y);
	else if (x > mid) return query(k << 1 | 1 , x , y);
	else return (query(k << 1 , x , mid) + query(k << 1 | 1 , mid + 1 , y)) % MOD;
}

int main() {
	n = read() , m = read();
	for (int i = 1 ; i <= n ; i ++) A[i] = read();
	init() , build(1 , 1 , n);
	for (int i = 1 ; i <= m ; i ++) {
		int tp = read() , x = read() , y = read();
		if (tp == 1) {
			int v = read();
			update(1 , x , y , f ^ v);
		}else printf("%I64d\n" , query(1 , x , y));
	}
	return 0;
}