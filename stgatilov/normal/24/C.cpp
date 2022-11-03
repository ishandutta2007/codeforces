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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

struct Point {
	int64 x, y;
	inline Point(int64 _x = 0, int64 _y = 0) : x(_x), y(_y) {}

	Point operator+ (const Point &b) const { return Point(x+b.x, y+b.y); }
	Point operator- (const Point &b) const { return Point(x-b.x, y-b.y); }
	Point operator* (int64 b) const { return Point(x*b, y*b); }
};

int n;
int64 k;
Point res[200<<10];
Point arr[200<<10];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%I64d", &n, &k);
	scanf("%I64d%I64d", &res[0].x, &res[0].y);
	for (int i = 0; i<n; i++) scanf("%I64d%I64d", &arr[i].x, &arr[i].y);

	for (int i = 0; i<n; i++) arr[i+n] = arr[i];
	n *= 2;

	for (int i = 0; i<n; i++) res[i+1] = arr[i] + arr[i] - res[i];

	int64 q = k / n;
	int64 r = k % n;

	Point ans = res[r] + (res[n] - res[0]) * q;
	printf("%I64d %I64d\n", ans.x, ans.y);

	return 0;
}