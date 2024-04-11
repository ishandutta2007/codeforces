#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;
#define M 1010
#define ep 1e-9
const double pi = acos(-1);

struct pnt {
	double x,y;
	pnt (double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator - (pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator + (pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator * (double a) {return pnt(x * a, y * a);}
	pnt operator / (double a) {return pnt(x / a, y / a);}
	double operator ^ (pnt a) {return x * a.y - y * a.x;}
	double operator & (pnt a) {return x * a.x + y * a.y;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {
    scanf("%lf %lf", &x, &y);
	}
} p[M], cr[M], P[M*M];

double r[M];
int n;

double f(int i, int j, int k) { return p[i] - p[j] & p[k] - p[j]; }
double area(int i, int j, int k) { return fabs(p[i] - p[j] ^ p[k] - p[j]); }

pnt outercenter(pnt a, pnt b, pnt c) {
	double c1 = ((a & a) - (b & b)) / 2, c2 = ((a & a) - (c & c)) / 2;
	double x0 = (c1 * (a.y - c.y) - c2 * (a.y - b.y)) / (a - b ^ a - c);
	double y0 = (c1 * (a.x - c.x) - c2 * (a.x - b.x)) / (a - c ^ a - b);
	return pnt(x0, y0);
}

bool chk(pnt a, pnt b, pnt c, int i, int j, int k) {
  int t;
  double r = (b - c).dist() / 2;
  pnt o = (b + c) / 2;
  int bf = 0;
  for (t = 0; t < n; t++) {
    if (t != i && t != j && t != k) {
      if ((p[t] - c ^ b - c) * (a - c ^ b - c) < -ep) {
        if ((p[t] - b).dist() < 2 * r && (p[t] - c).dist() < 2 * r) bf = 1;
      }
      if ((o - p[t]).dist() < r - ep) break;
    }
  }
  if (bf && t == n) return 1;
  return 0;
}

int main() {
  //freopen("in.txt", "r", stdin);
  int tc;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++) p[i].input();
  double ans = -1;
  for(int i = 0; i < n; i ++) for(int j = i + 1; j < n ;j ++) for(int k = j + 1; k < n; k ++) {
    if(f(i, j, k) < -ep || f(i, k, j) < -ep || f(j, i, k) < -ep) continue;
    int t;
    pnt a, b, c;

    if (f(i, j, k) < ep) {
      a = p[j], b = p[i], c = p[k];
      if (chk(a, b, c, i, j, k)) ans = max(ans, (b - c).dist() / 2);
    }
    else if (f(i, k, j) < ep) {
      a = p[k], b = p[i], c = p[j];
      if (chk(a, b, c, i, j, k)) ans = max(ans, (b - c).dist() / 2);
    }
    else if (f(j, i, k) < ep) {
      a = p[i], b = p[j], c = p[k];
      if (chk(a, b, c, i, j, k)) ans = max(ans, (b - c).dist() / 2);
    }
    else {
      double r = (p[i] - p[j]).dist() * (p[i] - p[k]).dist() * (p[j] - p[k]).dist() / area(i, j, k) / 2;
      pnt o = outercenter(p[i], p[j], p[k]);
      for (t = 0; t < n; t++) {
        if (t != i && t != j && t != k) {
          if ((o - p[t]).dist() < r - ep) break;
        }
      }
      if (t == n) {
        ans = max(ans, r);
      }
    }
  }
  if (ans < -ep) puts("-1");
  else printf("%.12lf\n", ans);
}