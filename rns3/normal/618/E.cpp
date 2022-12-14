#include <bits/stdc++.h>
using namespace std;
#define M 300010
#define X first
#define Y second

const int D = 500;
const double pi = acos(-1);

struct pnt {
	double x,y;
	pnt (double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator - (pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator + (pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator * (double a) {return pnt(x * a, y * a);}
	pnt operator / (double a) {return pnt(x / a, y / a);}
	double operator & (pnt a) {return x * a.x + y * a.y;}
} p[M];
double dist(pnt a) {return sqrt(a & a);}
double Cos[M], Sin[M];
int n, Q, S;
int del[M], al[M];
int len[M];

pnt st, en;

void get(int id) {
	int I = id / D;
	int A = al[I];
	A %= 360; if (A < 0) A += 360;
	pnt tmp = pnt(Cos[A], Sin[A]);
	tmp = tmp * len[I*D];
	st = p[I], en = st + tmp;
	for (int i = D * I + 1; i <= id; i++) {
		A += del[i]; st = en;
		A %= 360; if (A < 0) A += 360;
		en = en + (pnt(Cos[A], Sin[A]) * len[i]);
	}
}

void updateAdd(int id, pnt ADD) {
    int I = id / D; for (int i = I + 1; i < S; i++) p[i] = p[i] + ADD;
}

pnt Rot(pnt p, pnt v, int A){
	A %= 360; if (A < 0) A += 360;
	pnt ret = p;
	v = v - p;
	p = pnt(Cos[A], Sin[A]);
	ret.x += v.x * p.x - v.y * p.y;
	ret.y += v.x * p.y + v.y * p.x;
	return ret;
}


void updateRot(int id, int x) {
	int I = id / D;
	for (int i = I + 1; i < S; i++) {
		p[i] = Rot(st, p[i], x);
		al[i] += x;
	}
}

int main() {
//	freopen("E.in", "r", stdin);
	scanf("%d %d", &n, &Q);
	S = (n - 1) / D + 1;
	for (int i = 0; i < n; i++) {
		len[i] = 1;	if (i % D == 0) p[i/D] = pnt(i, 0);
	}
for (int i = 0; i < 360; i++) {
double x = i * pi / 180; Cos[i] = cos(x), Sin[i] = sin(x);
}

	while (Q--) {
		int type, id, x;
		scanf("%d %d %d", &type, &id, &x);
		id--;
		get(id);
		if (type == 1) {
			pnt q = en - st;
			double tmp = dist(q);
			q = q / tmp; q = q * x;
			len[id] += x;
			updateAdd(id, q);
		}
		else {
int t = -x;
			if (id % D == 0) al[id/D] += t; else del[id] += t;
            updateRot(id, t);
		}
		get(n - 1);
		printf("%.12lf %.12lf\n", en.x, en.y);
	}
}