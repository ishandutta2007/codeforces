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
#define maxn 20020
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

int lis[maxn], cs = 0, res[maxn], n;
bool vis[maxn];

int main(){
	int n; cin >> n;
	/*
	if (n == 1) {
		cout << "! " << 1 << endl;
		return 0;
	}
	*/
	int ans1, ans2, x, y;
	rep(i, 1, n) lis[i] = i; cs = n;
	while (cs > 1) {
		x = lis[cs], y = lis[cs - 1]; cs -= 2;
		cout << "? " << x << " " << y << endl;
		cin >> ans1;
		cout << "? " << y << " " << x << endl;
		cin >> ans2;
		if (ans1 > ans2) res[x] = ans1, lis[++cs] = y;
		else res[y] = ans2, lis[++cs] = x;
		vis[max(ans1, ans2)] = 1;
	}
	rep(i, 1, n) if (!vis[i]) {res[lis[cs]] = i; break;} 
	cout << "! ";
	rep(i, 1, n) cout << res[i] << " ";
	cout << endl;
	/*
	
	rep(i, 1, n) {
		cout << "? " << i << " " << ((i == 1) ? n : 1) << endl;
		cin >> ans1;
		cout << "? " << ((i == 1) ? n : 1) << " " << i << endl;
		cin >> ans2;
		
	}
	*/
	
	return 0;
}