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
#define maxn 200020
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

int n;
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
}p[maxn];

int main(){
	
		//freopen(".in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	read(n);
	if (n & 1) {
		printf("NO");
		return 0;
	}
	rep(i, 1, n) read(p[i].x), read(p[i].y), p[i].x <<= 1, p[i].y <<= 1; 
	int ptr = (n >> 1) + 1;
	int x = ((ll)p[1].x + p[ptr].x) >> 1, y = ((ll)p[1].y + p[ptr].y) >> 1;
	int _x, _y;
	rep(i, 2, (n >> 1)){
		ptr++;
		_x = ((ll)p[i].x + p[ptr].x) >> 1, _y = ((ll)p[i].y + p[ptr].y) >> 1;
		if (x != _x || y != _y){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}