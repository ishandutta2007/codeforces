#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 1010;

struct point {
	double x, y;
	
	point(){}
	
	point(double _x, double _y){
		x = _x;
		y = _y;
	}
	
};

struct line {
	double a, b, c;
	
	line(){}
	
	line(point A, point B){
		a = A.y - B.y;
		b = B.x - A.x;
		c = -a * A.x - b * A.y;
	}
	
};

double y[N][N];
point p[N], np[N];
double ans[N];

inline double dist(line &l, point &p){
	return l.a * p.x + l.b * p.y + l.c;
}

inline bool ls(double a, double b){
	return b - a >= eps;
}

inline point ill(line l1, line l2){
	double d = l1.a * l2.b - l2.a * l1.b;
	return point((l1.b * l2.c - l2.b * l1.c) / d, (l2.a * l1.c - l1.a * l2.c) / d);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			scanf("%lf", &y[i][j]);
		}
	}
	for(int i = 0; i < k; i++){
		int sz = 2;
		p[0] = point(i, 0);
		p[1] = point(i + 1, 0);
		for(int j = 0; j < n; j++){
			line l(point(i + 1, y[j][i + 1]), point(i, y[j][i]));
			int gl = -1, gr = -1;
			for(int z = 0; z < sz; z++){
				if(ls(0, dist(l, p[z]))){
					if(gl == -1){
						gl = z;
					}
					gr = z;
				}
			}
			if(gl != -1){
				point p1 = (gl == 0 ? point(i, y[j][i]) : ill(l, line(p[gl - 1], p[gl])));
				point p2 = (gr == sz - 1 ? point(i + 1, y[j][i + 1]) : ill(l, line(p[gr], p[gr + 1])));
				ans[j] += (p2.x - p1.x) * (p1.y + p2.y) / 2;
				for(int z = gl; z <= gr; z++){
					if(z == gl){
						ans[j] -= (p[z].x - p1.x) * (p1.y + p[z].y) / 2;
					}
					else{
						ans[j] -= (p[z].x - p[z - 1].x) * (p[z - 1].y + p[z].y) / 2;
					}
					if(z == gr){
						ans[j] -= (p2.x - p[z].x) * (p[z].y + p2.y) / 2;
					}
				}
				int nsz = 0;
				for(int z = 0; z < gl; z++){
					np[nsz++] = p[z];
				}
				np[nsz++] = p1;
				np[nsz++] = p2;
				for(int z = gr + 1; z < sz; z++){
					np[nsz++] = p[z];
				}
				sz = nsz;
				for(int z = 0; z < sz; z++){
					p[z] = np[z];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%.18lf\n", ans[i]);
	}
	return 0;
}