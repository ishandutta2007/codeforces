#include <cstdio>
#include <iostream>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 1e5 + 1;

int n, q, a[N << 2], b[N << 2], c[N << 2], a_b_c[N << 2], a_b[N << 2], a_c[N << 2], b_c[N << 2], ab[N << 2], bc[N << 2], ab_c[N << 2], bc_a[N << 2], ab_bc[N << 2];
char s[N + 1];

int min(int a, int b, int c){
	return min(min(a, b), c);
}

void pull(int i){
	a[i] = a[le] + a[ri];
	b[i] = b[le] + b[ri];
	c[i] = c[le] + c[ri];
	a_b[i] = min(b[le] + a_b[ri], a_b[le] + a[ri]);
	b_c[i] = min(c[le] + b_c[ri], b_c[le] + b[ri]);
	a_c[i] = a_c[le] + a_c[ri];
	a_b_c[i] = min(c[le] + a_b_c[ri], a_b_c[le] + a[ri], b_c[le] + a_b[ri]);
	ab[i] = ab[le] + ab[ri];
	bc[i] = bc[le] + bc[ri];
	ab_c[i] = min(a_c[le] + ab_c[ri], ab_c[le] + ab[ri]);
	bc_a[i] = min(bc[le] + bc_a[ri], bc_a[le] + a_c[ri]);
	ab_bc[i] = min(ab_bc[le] + ab[ri], bc_a[le] + ab_c[ri], bc[le] + ab_bc[ri]);
}

void point(int i, int l){
	if(s[l] == 'a'){
		a[i] = a_b[i] = a_c[i] = a_b_c[i] = ab[i] = ab_c[i] = bc_a[i] = ab_bc[i] = 0;
		b[i] = c[i] = b_c[i] = bc[i] = 1;
	}else if(s[l] == 'b'){
		b[i] = a_b[i] = b_c[i] = a_b_c[i] = ab[i] = bc[i] = ab_c[i] = bc_a[i] = ab_bc[i] = 0;
		a[i] = c[i] = a_c[i] = 1;
	}else if(s[l] == 'c'){
		c[i] = b_c[i] = a_c[i] = a_b_c[i] = bc[i] = ab_c[i] = bc_a[i] = ab_bc[i] = 0;
		a[i] = b[i] = a_b[i] = ab[i] = 1;
	}
}

void build(int i, int l, int r){
	if(l == r){
		point(i, l);
		return;
	}
	int mid = (l + r) >> 1;
	build(le, l, mid);
	build(ri, mid + 1, r);
	pull(i);
}

int P;
char C;

void mod(int i, int l, int r){
	if(l == r){
		s[l] = C;
		point(i, l);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= P) mod(le, l, mid);
	else mod(ri, mid + 1, r);
	pull(i);
}

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	build(1, 1, n);
	while(q--){
		scanf("%d %c", &P, &C);
		mod(1, 1, n);
		printf("%d\n", ab_bc[1]);
	}
	return 0;
}