#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int
#define ls ch[x][0]
#define rs ch[x][1]
#define lowbit(x) x & -x
#define maxr 100005
#define maxn 300015
#define maxm
#define X(x) 
#define Y(x)
#define TAN(x)
#define next NEXT
#define hash HASH
#define M 
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define esrep(i, x, NS) for (register int i = NS :: h[x]; i; i = NS :: e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); bool f = 1; x = 0;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	if (!f) x = -x;
}
int n;
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
	bool operator < (const point b) const{
		return (y == b.y) ? x < b.x : y > b.y;
	}
}p[maxn];
int lis[maxn];

int sum[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void modify(int l, int r, int o){
	if (l == r){ sum[o] = qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) modify(l, mid, o << 1);
	else modify(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get_left(int l, int r, int o){
	if (l == r) return sum[o];
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return get_left(l, mid, o << 1);
	else return sum[o << 1] + get_left(mid + 1, r, o << 1 | 1);
}
int get_right(int l, int r, int o){
	if (l == r) return sum[o];
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return sum[o << 1 | 1] + get_right(l, mid, o << 1);
	else return get_right(mid + 1, r, o << 1 | 1);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	read(n);
	rep(i, 1, n) read(p[i].x), read(p[i].y);
	rep(i, 1, n) lis[i] = p[i].x;
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) p[i].x = lower_bound(lis + 1, lis + 1 + n, p[i].x) - lis;
	rep(i, 1, n) lis[i] = p[i].y;
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) p[i].y = lower_bound(lis + 1, lis + 1 + n, p[i].y) - lis;
	sort(p + 1, p + 1 + n);
	ll ans = 0;
	qd = 1;
	rep(i, 1, n){
		qx = p[i].x, modify(1, n, 1);
		ll le = get_left(1, n, 1);
		ll ri = get_right(1, n, 1);
		if (i < n && p[i + 1].y == p[i].y) qx = p[i + 1].x, ri -= get_right(1, n, 1);
		ans += le * ri;
	}
	printf("%I64d", ans);
	return 0;
}