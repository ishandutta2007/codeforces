#include <bits/stdc++.h>
using namespace std;
#define M 5010

typedef long long LL;

struct pnt {
	int x, y;
	pnt (int x = 0, int y = 0) : x(x), y(y) {}
	pnt operator +(pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator -(pnt a) {return pnt(x - a.x, y - a.y);}
	//pnt operator /(int a) {return pnt(x / a, y / a);}
	//pnt operator *(int a) {return pnt(x * a, y * a);}
	LL operator ^ (pnt a) {return 1LL * x * a.y - 1LL * y * a.x;}
	LL operator & (pnt a) {return 1LL * x * a.x + 1LL * y * a.y;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {scanf("%d %d", &x, &y);}
	void print() {printf("%d %d\n", x, y);}
} con[M], p[M];

int n;

bool cmp(pnt a, pnt b) {
	if (abs(a.x - b.x) > 0) return a.x < b.x;
	return a.y < b.y;
}

bool cmp1(pnt a, pnt b) {
	LL tmp = a - p[0] ^ b - p[0];
	if (abs(tmp) > 0) return tmp > 0;
	LL u = a - p[0] & a - p[0], v = b - p[0] & b - p[0];
	return u < v;
}

void graham() {
	sort(p, p + n, cmp);
	sort(p + 1, p + n, cmp1);
	int k = 0;
	for (int i = 0; i < n; i ++) {
		while (k > 1 && (con[k - 1] - con[k - 2] ^ p[i] - con[k - 2]) <= 0) k --;
		con[k ++] = p[i];
	}
	n = k;
	for (int i = 0; i < n; i++) p[i] = con[i];
}

LL s;

inline LL F(int i, int j, int k) {
  return abs((p[i] - p[j]) ^ (p[k] - p[j]));
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %I64d", &n, &s);
  for (int i = 0; i < n; i++) p[i].input();
  graham();
  if (n == 3) {
    (p[0] + p[1] - p[2]).print();
    (p[2] + p[1] - p[0]).print();
    (p[0] + p[2] - p[1]).print();
    return 0;
  }
  LL mx = 0;

  int a, b, c;

  for (int i = 0; i < n; i++) {
    int tc = (i + 2) % n;
    for (int j = i + 1; j < n; j++) {
      while (F(i, j, tc) < F(i, j, (tc + 1) % n)) {
        tc++; if (tc >= n) tc -= n;
      }
      LL tp = F(i, j, tc);
      if (tp > mx) mx = tp, a = i, b = j, c = tc;
    }
  }
  pnt A = p[a] + p[b] - p[c];
  pnt B = p[a] + p[c] - p[b];
  pnt C = p[b] + p[c] - p[a];
  A.print();
  B.print();
  C.print();
}