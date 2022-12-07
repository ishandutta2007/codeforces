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
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define islower(ch) ('a' <= ch && ch <= 'z') 
#define isdigit(ch) ('0' <= ch && ch <= '9')  
int reads(char* s){
	int l = 0; char ch = gc(); while (!islower(ch)) ch = gc();
	while (islower(ch)) s[l++] = ch, ch = gc(); s[l] = '\0'; return l;
}

#define maxsig 26
int mxl[maxn], go[maxn][maxsig], siz[maxn], par[maxn], last = 1, ct = 1;
void extend(int ch) {
	int p = last, np = last = ++ct; siz[np] = 1, mxl[np] = mxl[p] + 1;
	while (p && !go[p][ch]) go[p][ch] = np, p = par[p];
	if (p) {
		int q = go[p][ch];
		if (mxl[q] == mxl[p] + 1) par[np] = q;
		else {
			int nq = ++ct; mxl[nq] = mxl[p] + 1, par[nq] = par[q], par[q] = par[np] = nq;
			memcpy(go[nq], go[q], sizeof(go[q]));
			while (p && go[p][ch] == q) go[p][ch] = nq, p = par[p];
		}
	}else par[np] = 1;
}
vector<int> g[maxn];
void dfs(int x) {
	int si = g[x].size();
	srep(i, 0, si) {
		int op = g[x][i];
		dfs(op);
		siz[x] += siz[op];
	}
}
ll num[maxn];
ll dp(int x){
	if (num[x]) return num[x]; ll& ans = num[x]; ans = siz[x];
	srep(i, 0, maxsig) { if (go[x][i]) ans += dp(go[x][i]); }
	return ans;
} 
void update(){
	rep(i, 1, ct) g[par[i]].pb(i);
	dfs(1), dp(1);
}


char s[maxn];
int main(){
	reads(s + 1);
	int n = strlen(s + 1), m, x;
	rep(i, 1, n) extend(s[i] - 'a'); update(); 
	//read(m);
	rep(i, 1, 1) {
		int now = 1;
		read(x), x += siz[1];
		if (x > num[1]) printf("No such line.");
		else {
			while (1) {
				x -= siz[now]; 
				if (x <= 0) break;
				srep(i, 0, maxsig) {
					if (x <= num[go[now][i]]) {printf("%c", 'a' + i), now = go[now][i]; break;}
					x -= num[go[now][i]];
				}
			}
		} 
		printf("\n");
	}
	return 0;
}