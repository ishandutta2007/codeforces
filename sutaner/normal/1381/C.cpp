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

int ptr[maxn];
vector<int> pos[maxn];
set<pii> s;
int ans[maxn], a[maxn];
int main(){
	int T, x, y, n;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &x, &y);
		rep(i, 1, n) scanf("%d", a + i), pos[a[i]].pb(i);
		int f = -1;
		rep(i, 1, n + 1) {
			ptr[i] = 0;
			if (pos[i].empty()) {f = i; continue;}
			s.insert(pii(pos[i].size(), i));
		}
		assert(f != -1);
		rep(i, 1, n) ans[i] = f;
		int ct = n;
		while (x && !s.empty()){
			pii op = *s.rbegin(); s.erase(op);
			ans[pos[op.se][ptr[op.se]++]] = op.se;
			op.fi--;
			if (op.fi) s.insert(op);
			x--, y--;
			ct--;
		} 
		while (y && !s.empty()){
			pii op = *s.rbegin(); s.erase(op);
			if (s.empty()) break;
			pii op2 = *s.rbegin(); s.erase(op2);
			if (ct == 3 && !s.empty()) {
				pii op3 = *s.rbegin(); s.erase(op3);
				
				ans[pos[op.se][ptr[op.se]++]] = op2.se;
				y--, ct--, op.fi--;
				if (!y) break;
				if (op.fi) s.insert(op);
				
				ans[pos[op2.se][ptr[op2.se]++]] = op3.se;
				y--, ct--, op2.fi--;
				if (!y) break;
				if (op2.fi) s.insert(op2);
				
				ans[pos[op3.se][ptr[op3.se]++]] = op.se;
				y--, ct--, op3.fi--;
				if (!y) break;
				if (op3.fi) s.insert(op3); 
			}
			else {
				ans[pos[op.se][ptr[op.se]++]] = op2.se;
				y--, ct--, op.fi--;
				if (!y) break;
				if (op.fi) s.insert(op);
				
				ans[pos[op2.se][ptr[op2.se]++]] = op.se;
				y--, ct--, op2.fi--;
				if (!y) break;
				if (op2.fi) s.insert(op2);
			}
		}
		if (y) printf("NO\n");
		else {printf("YES\n"); rep(i, 1, n) printf("%d ", ans[i]); printf("\n");}
		rep(i, 1, n + 1) ptr[i] = 0, pos[i].clear(); s.clear();
	} 
	return 0;
}