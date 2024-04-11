#include <cstdio>
#include <cmath>

const int MAXN = 3E5 + 10;

int n, m;

struct matrix{
	double a[2][2];

	matrix& reset(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
	}

	matrix& set(){
		a[0][0] = 1;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
	}

	matrix& operator=(const matrix &r){
		a[0][0] = r.a[0][0];
		a[0][1] = r.a[0][1];
		a[1][0] = r.a[1][0];
		a[1][1] = r.a[1][1];
		return *this;
	}

	void output(){
		printf("%.6lf %.6lf %.6lf %.6lf\n", a[0][0], a[0][1], a[1][0], a[1][1]);
	}
};

matrix operator+(const matrix &l, const matrix &r){
	return (matrix){
		l.a[0][0] + r.a[0][0],
		l.a[0][1] + r.a[0][1],
		l.a[1][0] + r.a[1][0],
		l.a[1][1] + r.a[1][1]
	};
}

matrix operator-(const matrix &l, const matrix &r){
	return (matrix){
		l.a[0][0] - r.a[0][0],
		l.a[0][1] - r.a[0][1],
		l.a[1][0] - r.a[1][0],
		l.a[1][1] - r.a[1][1]
	};
}

matrix operator*(const matrix &l, const matrix &r){
	return (matrix){
		l.a[0][0] * r.a[0][0] + l.a[0][1] * r.a[1][0],
		l.a[0][0] * r.a[0][1] + l.a[0][1] * r.a[1][1],
		l.a[1][0] * r.a[0][0] + l.a[1][1] * r.a[1][0],
		l.a[1][0] * r.a[0][1] + l.a[1][1] * r.a[1][1]
	};
}

matrix operator*(const matrix &l, double r){
	return (matrix){
		l.a[0][0] * r,
		l.a[0][1] * r,
		l.a[1][0] * r,
		l.a[1][1] * r
	};
}

int L, R;
matrix C1, C2;
matrix s[MAXN << 2];
matrix add[MAXN << 2], prod[MAXN << 2];

void push(int u, matrix p, matrix a){
	s[u] = p * s[u] + a;
	prod[u] = p * prod[u];
	add[u] = p * add[u] + a;
}

void pushDown(int u){
	push(u << 1, prod[u], add[u]);
	push(u << 1 | 1, prod[u], add[u]);
	prod[u].set();
	add[u].reset();
}

void build(int u, int l, int r){
	if (l + 1 == r){
		s[u].a[0][0] = l;
		s[u].a[0][1] = l;
		s[u].a[1][0] = 0;
		s[u].a[1][1] = 0;
		return;
	}
	prod[u].set();
	add[u].reset();
	int m = l + r >> 1;
	build(u << 1, l, m);
	build(u << 1 | 1, m, r);
}

void update(int u, int l, int r){
	if (L <= l && r <= R){
		push(u, C1, C2);
		return;
	}
	pushDown(u);
	int m = l + r >> 1;
	if (L < m)
		update(u << 1, l, m);
	if (m < R)
		update(u << 1 | 1, m, r);
}

void query(int u, int l, int r){
	if (l + 1 == r){
		C1 = s[u];
		return;
	}
	pushDown(u);
	int m = l + r >> 1;
	if (L < m)
		query(u << 1, l, m);
	else
		query(u << 1 | 1, m, r);
}

int main(){
	scanf("%d%d", &n, &m);
	build(1, 1, n + 1);
	matrix A;
	R = n + 1;
	for (int com, a, b, i = 0; i < m; ++i){
		scanf("%d%d%d", &com, &a, &b);
		if (a == 1)
			A.reset();
		else
			L = a - 1, query(1, 1, n + 1), A = C1;

		if (com == 1){
			L = a, query(1, 1, n + 1), C2 = C1 - A;
			double ratio = b / sqrt(C2.a[0][0] * C2.a[0][0] + C2.a[1][0] * C2.a[1][0]);
			C2 = C2 * ratio;
			C1.set();
			L = a, update(1, 1, n + 1);
		}
		else{
			double t = (360 - b) * M_PI / 180;
			C1 = (matrix){cos(t), -sin(t), sin(t), cos(t)};
			C2 = A - C1 * A;
			L = a, update(1, 1, n + 1);
		}
		L = n, query(1, 1, n + 1);
		printf("%.10lf %.10lf\n", C1.a[0][0], C1.a[1][0]);
	}
	return 0;
}