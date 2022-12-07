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

char s[maxn];


struct ele{
	int x, y, dir;
	ele(int x, int y, int dir): x(x), y(y), dir(dir){}
	ele(){}
	bool operator < (const ele b) const{
		return (x == b.x) ? ((y == b.y) ? dir < b.dir : y < b.y) : x < b.x;
	}
};
set<ele> ss; 

int main(){
	int T, x, y, n;
	scanf("%d", &T);
	rep(TT, 1, T){
		ss.clear();
		scanf("%s", s + 1);
		x = y = 0, n = strlen(s + 1);
		int t = 0; 
		rep(i, 1, n) {
			if (s[i] == 'N') {
				if (!ss.count(ele(x, y, 0))) t += 5, ss.insert(ele(x, y, 0));
				else t++;
				x++;
				ss.insert(ele(x, y, 1));
			}
			else if (s[i] == 'S') {
				if (!ss.count(ele(x, y, 1))) t += 5, ss.insert(ele(x, y, 1));
				else t++;
				x--;
				ss.insert(ele(x, y, 0));
			}
			else if (s[i] == 'W') {
				if (!ss.count(ele(x, y, 2))) t += 5, ss.insert(ele(x, y, 2));
				else t++;
				y++;
				ss.insert(ele(x, y, 3));
			}
			else if (s[i] == 'E') {
				if (!ss.count(ele(x, y, 3))) t += 5, ss.insert(ele(x, y, 3));
				else t++;
				y--;
				ss.insert(ele(x, y, 2));
			} 
		}
		printf("%d\n", t);
	}
	return 0;
}