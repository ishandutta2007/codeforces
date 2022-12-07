#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 10020
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

inline int ceiling(int n, int k){
	return (n - 1) / k + 1;
}
int bfs[maxn], head = 0, tail = 0;
bool ok[maxn];
int main(){
	int n;
	cin >> n;
	int mx = 0, mx2 = 0;
	rep(i, 1, n) mx = max(mx, n - ceiling(n, i) - i + 1);
	if (!mx) {cout << 0 << endl; return 0;}
	rep(i, 1, n) if (n - ceiling(n, i) - i + 1 == mx) {mx2 = i; break;}  
	int k = mx2;
	rep(i, 1, n){
		if (i % k == 1) continue;
		bfs[++head] = i;
	}
	int cnt = 0, x;
	while (cnt != mx){
		cout << k << ' ';
		int rest = k;
		while (rest){
			cout << bfs[++tail] << ' ';
			ok[bfs[tail]] = 1, cnt++;
			if (tail == maxn - 1) tail = 0;
			rest--;
		}
		cout << endl;
		cin >> x;
		if (x == -1) return 0;
		rest = k;
		while (rest){
			if (ok[x]) {
				bfs[++head] = x;
				if (head == maxn - 1) head = 0;
				cnt--;
				ok[x] = 0;
			}
			rest--;
			x++;
			if (x > n) x = 1;
		}
	}
	cout << 0 << endl;
	return 0;
}