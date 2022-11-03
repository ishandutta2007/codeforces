//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

struct Point {
	double x, y;
	inline Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

	Point operator+ (const Point &b) const { return Point(x + b.x, y + b.y); }
	Point operator- (const Point &b) const { return Point(x - b.x, y - b.y); }
	Point operator* (double b) const { return Point(x * b, y * b); }
};

static const double PI = 2.0 * acos(0.0);
double len = 2 * 10.0 * sin(0.3*PI);
Point Side(int i) {
	double dang = 0.8 * PI;
	double ang = dang * i;
	return Point(cos(ang), sin(ang)) * len;
}                        

int n;
Point pts[512];
vector<int> arr;
int color[512];

bool used[512];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);

	for (int i = 0; i<n; i++) {
		pts[5*i] = i * len;
		for (int j = 1; j<5; j++)
			pts[5*i+j] = pts[5*i+j-1] + Side(j-1);
	}

	arr.push_back(0);
	for (int i = 0; i<n; i++) arr.push_back(5*i+1);
	for (int i = n-1; i>=0; i--) {
		arr.push_back(5*i+2);
		arr.push_back(5*i+3);
		arr.push_back(5*i+4);
		arr.push_back(5*i+0);
	}
	
	
	int cc = 0;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<5; j++) {
			if (i > 0 && j == 0)
				color[5*i] = color[5*(i-1)+1];
			else 
				color[5*i+j] = cc++;
		}
		
	printf("%d\n", cc);
	for (int i = 0; i<5*n; i++)
		if (!used[color[i]]) {
			printf("%0.20lf %0.20lf\n", pts[i].x, pts[i].y);
			used[color[i]] = true;
		}

	for (int i = 0; i<n; i++) {
		printf("%d ", color[5*i+0] + 1);
		printf("%d ", color[5*i+2] + 1);
		printf("%d ", color[5*i+4] + 1);
		printf("%d ", color[5*i+1] + 1);
		printf("%d" , color[5*i+3] + 1);
		printf("\n");
	}

	for (int i = 0; i<arr.size(); i++)
		printf("%d ", color[arr[i]] + 1);
	printf("\n");

	return 0;
}