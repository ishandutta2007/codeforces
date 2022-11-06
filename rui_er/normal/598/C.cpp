//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const long double pi = acos(-1);

int n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dot {
	int x, y, id;
	long double angle;
	friend bool operator < (const Dot& a, const Dot& b) {
		return a.angle < b.angle;
	}
}a[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].angle = atan2(a[i].x, a[i].y);
		a[i].id = i;
	}
	sort(a+1, a+1+n);
	long double ans = a[1].angle - a[n].angle + 2 * pi;
	int ans1 = a[n].id, ans2 = a[1].id;
	rep(i, 2, n) {
		long double now = a[i].angle - a[i-1].angle;
		if(now < ans) {
			ans = now;
			ans1 = a[i-1].id;
			ans2 = a[i].id;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}