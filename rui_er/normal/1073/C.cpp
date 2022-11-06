//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Dot {
	int x, y;
	Dot(int a=0, int b=0) : x(a), y(b) {}
	~Dot() {}
	friend bool operator == (const Dot &a, const Dot &b) {return a.x == b.x && a.y == b.y;}
}now, dst;
int dis(Dot a, Dot b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}
bool able(Dot a, Dot b, int stp=n) {
	int qwq = dis(a, b);
	return (qwq <= stp) && ((qwq & 1) == (stp & 1));
}
void go(Dot &a, char dir, int delta=1) {
	if(dir == '$') return;
	if(dir == 'U') a.y += delta;
	else if(dir == 'D') a.y -= delta;
	else if(dir == 'L') a.x -= delta;
	else a.x += delta;
}
bool check(int M) {
	if(!M) return now == dst;
	int l = 1, r = M, ans = 0;
	rep(i, l, r-1) go(now, s[i], -1);
	while(r <= n) {
		go(now, s[l-1], 1);
		go(now, s[r], -1);
		if(able(now, dst, M)) {ans = 1; break;}
		++l; ++r;
	}
	if(r > n) {--l; --r;}
	rep(i, l, r) go(now, s[i], 1);
	return ans;
}

int main() {
	scanf("%d%s%d%d", &n, s+1, &dst.x, &dst.y);
	if(!able(now, dst)) return puts("-1")&0;
	s[0] = '$';
	rep(i, 1, n) go(now, s[i]);
	int L = 0, R = n, ans = n;
	while(R - L >= 5) {
		int M = (L + R) >> 1;
		if(check(M)) R = M - 1, ans = M;
		else L = M + 1;
	}
	rep(i, L, R) if(check(i)) chkmin(ans, i);
	printf("%d\n", ans);
	return 0;
}