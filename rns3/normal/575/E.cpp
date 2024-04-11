#include <bits/stdc++.h>
using namespace std;
#define M 2000010
#define ep 1e-9
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define INF 1e5

typedef long long LL;

int n, cnt;

struct pnt {
	LL x,y;
	pnt (LL x = 0, LL y = 0) : x(x), y(y) {}
	pnt operator - (pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator + (pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator * (LL a) {return pnt(x * a, y * a);}
	pnt operator / (LL a) {return pnt(x / a, y / a);}
	LL operator ^ (pnt a) {return x * a.y - y * a.x;}
	LL operator & (pnt a) {return x * a.x + y * a.y;}
} con[M], p[M];

bool cmp(pnt a, pnt b) {
	if (fabs(a.x - b.x) > ep) return a.x < b.x;
	return a.y < b.y;
}

bool cmp1(pnt a, pnt b) {
	LL tmp = a - p[0] ^ b - p[0];
	if (fabs(tmp) > ep) return tmp > 0;
	LL u = a - p[0] & a - p[0], v = b - p[0] & b - p[0];
	return u < v;
}

int get_convex_hull() {
	n = cnt;
	sort(p, p + n, cmp);
	sort(p + 1, p + n, cmp1);
	int k = 0;
	for (int i = 0; i < n; i ++) {
		while (k > 1 && (con[k - 1] - con[k - 2] ^ p[i] - con[k - 2]) <= 0) k --;
		con[k ++] = p[i];
	}
	return k;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pnt s[10], q[10];

double dist(pnt a) {return sqrt(a & a);}

double Radius(pnt a, pnt b, pnt c) {
	double A = dist(b - c), B = dist(a - c), C = dist(a - b);
	double P = (A + B + C) / 2;
	return A * B * C / sqrt(P * (P - A)) / sqrt((P - B) * (P - C)) / 4;
}

int main() {
//freopen("E.in", "r", stdin);
	scanf("%d", &n);
	int x, y, v, xx, yy;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &v);
		for (int j = 0; j < 4; j++) {
			xx = x + v * dx[j], yy = y + v * dy[j];
			if (xx >= 0 && yy >= 0 && xx <= INF && yy <= INF) p[cnt++] = pnt(xx, yy);
      if (xx < 0) {
      	p[cnt++] = pnt(0, min(y + v - x, INF)); p[cnt++] = pnt(0, max(0, y + x - v));
      }
      else if (yy < 0) {
      	p[cnt++] = pnt(min(x + v - y, INF), 0); p[cnt++] = pnt(max(0, x + y - v), 0);
      }
      else if (xx > INF) {
      	p[cnt++] = pnt(INF, min(INF, y + v - (INF - x)));
				p[cnt++] = pnt(INF, max(0, y - (v - (INF - x))));
      }
      else if (yy > INF) {
      	p[cnt++] = pnt(min(INF, x + v - (INF - y)), INF);
				p[cnt++] = pnt(max(0, x - (v - (INF - y))), INF);
      }
		}
	}
	int t = get_convex_hull(), id;
	double mx = 0;
	for (int i = 0; i < t; i++) {
		pnt a = con[i], b = con[(i+1)%t], c = con[(i+2)%t];
		double r = Radius(a, b, c);
		if (r > mx) {mx = r; id = i;}
	}
	for (int i = 0; i < 3; i++) {
		printf("%I64d %I64d\n", con[(id+i)%t].x, con[(id+i)%t].y);
	}
}