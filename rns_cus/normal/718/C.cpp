#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define N 200020

#define left(I) (I << 1)
#define right(I) (I << 1 | 1)

struct matrix {
	int num[3][3];
	matrix() {
		memset(num, 0, sizeof num);
	}
	matrix operator + (const matrix &b) {
	    matrix c;
		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++) c.num[i][j] = (num[i][j] + b.num[i][j]) % mod;
		}
		return c;
	}
	matrix operator - (const matrix &b) {
	    matrix c;
		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++) c.num[i][j] = (num[i][j] - b.num[i][j]) % mod;
		}
		return c;
	}
	matrix operator * (const matrix &b) {
		matrix c;
        for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++) {
				for (int k = 0; k < 2; k ++) {
					c.num[i][j] = (c.num[i][j] + 1ll * num[i][k] * b.num[k][j]) % mod;
				}
			}
        }
        return c;
	}
	void operator = (const matrix &b){
        for(int i = 0; i < 2; i ++) for(int j = 0; j < 2; j ++) num[i][j] = b.num[i][j];
	}
}II, I;

void init(){
    II.num[0][0] = II.num[0][1] = II.num[1][0] = 1;
    II.num[1][1] = 0;
    I.num[0][0] = I.num[1][1] = 1;
    I.num[1][0] = I.num[0][1] = 0;
}

matrix pow(long long m) {
	matrix rlt = I, X = II;
	while (m) {
		if (m & 1) rlt = rlt * X;
		X = X * X, m >>= 1;
	}
	return rlt;
}


matrix add[N << 2], sum[N << 2];
int a[N];

void push_up(int id) {
    sum[id] = sum[left(id)] + sum[right(id)];
}

void push_down(int id){
    add[left(id)] = add[left(id)] * add[id];
    add[right(id)] = add[right(id)] * add[id];
    sum[left(id)] = sum[left(id)] * add[id];
    sum[right(id)] = sum[right(id)] * add[id];
    add[id] = I;
    return;
}

void build(int l, int r, int id) {
    if (l == r) {
        add[id] = pow(a[l]);
        sum[id] = add[id];
        return;
    }
    add[id] = I;
    int m = (l + r) >> 1;
    build(l, m, left(id));
    build(m + 1, r, right(id));
    push_up(id);
}

void update(int L, int R, matrix v, int l, int r, int id){
    if(L <= l && r <= R){
        sum[id] = v * sum[id];
        add[id] = v * add[id];
        return;
    }
    push_down(id);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, v, l, m, left(id));
    if(m < R) update(L, R, v, m + 1, r, right(id));
    push_up(id);
}

int calc(int L, int R, int l, int r, int id){
    if(L <= l && r <= R){ return sum[id].num[0][1]; }
    push_down(id);
    int m = (l + r) >> 1, tot = 0;
    if(L <= m) tot = (tot + calc(L, R, l, m, left(id))) % mod;
    if(m < R)  tot = (tot + calc(L, R, m + 1, r, right(id))) % mod;
    return tot;
}

int st, en, x, n, query, type;
matrix tmp;

int main(){
    init();

    scanf("%d %d", &n, &query);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    build(1, n, 1);
    while(query --){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d %d %d", &st, &en, &x);
            tmp = pow(x);
            update(st, en, tmp, 1, n, 1);
        }
        else{
            scanf("%d %d", &st, &en);
            printf("%d\n", calc(st, en, 1, n, 1));
        }
    }

}