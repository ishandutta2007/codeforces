#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, x; 

int st[maxn], cs = 0;

struct point{
	ll x, y;
	point(ll x, ll y): x(x), y(y){}
	point(){}
}p[maxn];
point operator + (point a, point b){
	return point(a.x + b.x, a.y + b.y);
}
point operator - (point a, point b){
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

int main(){
	
		//freopen(".in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	int x;	
	read(n);
	rep(i, 1, n) read(x), p[i] = point(i, p[i - 1].y + x);
	st[++cs] = 0;
	rep(i, 1, n){
		while (cs > 1 && cross(p[i] - p[st[cs]], p[st[cs]] - p[st[cs - 1]]) >= 0) cs--;
		st[++cs] = i;
	}
	rep(i, 1, cs){
		double ans = 1.0 * (p[st[i]].y - p[st[i - 1]].y) / (p[st[i]].x - p[st[i - 1]].x);
		rep(j, p[st[i - 1]].x + 1, p[st[i]].x){
			printf("%.9lf\n", ans);
		}
	}
	return 0;
}