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
#define maxn 100115
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
int n, k, num[maxn];
char s[maxn];

int sum[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void init(int l, int r, int o){
	if (l == r) {sum[o] = num[l]; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get_left_1(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1]) return get_left_1(l, mid, o << 1);
	else return get_left_1(mid + 1, r, o << 1 | 1);
}
int get_right_1(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1 | 1]) return get_right_1(mid + 1, r, o << 1 | 1);
	else return get_right_1(l, mid, o << 1);
}
int get_left_0(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1] < (mid + 1 - l)) return get_left_0(l, mid, o << 1);
	else return get_left_0(mid + 1, r, o << 1 | 1);
}
int get_right_0(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1 | 1] < r - mid) return get_right_0(mid + 1, r, o << 1 | 1);
	else return get_right_0(l, mid, o << 1);
}
int get_left_1(){
	return (sum[1]) ? get_left_1(1, n, 1) : -1;
}
int get_right_1(){
	return (sum[1]) ? get_right_1(1, n, 1) : -1;
}
int get_left_0(){
	return (sum[1] == n) ? -1 : get_left_0(1, n, 1);
}
int get_right_0(){
	return (sum[1] == n) ? -1 : get_right_0(1, n, 1);
}
void modify(int l, int r, int o){
	if (l == r) {sum[o] = qd;return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) modify(l, mid, o << 1);
	else modify(mid + 1, r, o << 1 | 1);
	pu(o);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	scanf("%d%d%s", &n, &k, s + 1);
	int l1, l0, r1, r0;
	rep(i, 1, n) num[i] = s[i] - '0';
	init(1, n, 1);
	l1 = get_left_1();
	r1 = get_right_1();
	l0 = get_left_0();
	r0 = get_right_0();
	if (((r1 - l1 + 1) <= k) || ((r0 - l0 + 1) <= k)) {printf("tokitsukaze");return 0;}
	
	rep(i, 1, k) num[i] = 0;
	init(1, n, 1);
	rep(i, 1, n - k + 1){
		l1 = get_left_1();
		r1 = get_right_1();
		l0 = get_left_0();
		r0 = get_right_0();
		if (!(((r1 - l1 + 1) <= k) || ((r0 - l0 + 1) <= k))) {printf("once again");return 0;}
		qx = i, qd = s[i] - '0', modify(1, n, 1);
		qx = i + k, qd = 0, modify(1, n, 1);
	}
	
	rep(i, 1, n) num[i] = s[i] - '0';
	rep(i, 1, k) num[i] = 1;
	init(1, n, 1);
	rep(i, 1, n - k + 1){
		l1 = get_left_1();
		r1 = get_right_1();
		l0 = get_left_0();
		r0 = get_right_0();
		if (!(((r1 - l1 + 1) <= k) || ((r0 - l0 + 1) <= k))) {printf("once again");return 0;}
		qx = i, qd = s[i] - '0', modify(1, n, 1);
		qx = i + k, qd = 1, modify(1, n, 1);
	}
	printf("quailty");
	//one step, or two steps win, otherwise draw...
	return 0;
}