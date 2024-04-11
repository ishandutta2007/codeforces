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
#define maxn
#define maxm 10020
#define maxt 1020
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

/*
struct ___int128{
	ll x, y;
	bool f;
	operator + (___int128 b) {
	}
	operator - (___int128 b) {
	}
	operator = (long long int k){	
		
	}
	___int128(){}
}
*/

int n, m, g, r, a[maxm];
/*
ll dp[maxm][maxt];
int vis[maxm][maxt];
inline void upd(ll& ans, ll x){
	if (x == -1) return;
	ans = (ans == -1) ? x : min(ans, x);
}
ll DP(int pos, int tim){
	if (vis[pos][tim] == 1) return dp[pos][tim];
	if (vis[pos][tim] == 2) return -1;
	vis[pos][tim] = 2;
	ll& ans = dp[pos][tim];
	if (!tim) {
		ll _ans = DP(pos, g);
		ans = (_ans == -1) ? -1 : (_ans + r);
	}
	else ans = -1; 
	//ans = (tim) ? -1 : (DP(pos, g) + r);
	if (n - a[pos] <= tim) upd(ans, n - a[pos]);
	ll ansl = (pos > 1 && a[pos] - a[pos - 1] <= tim && DP(pos - 1, tim - a[pos] + a[pos - 1]) != -1) ? (DP(pos - 1, tim - a[pos] + a[pos - 1]) + a[pos] - a[pos - 1]) : -1;
	ll ansr = (pos < m && a[pos + 1] - a[pos] <= tim && DP(pos + 1, tim - a[pos + 1] + a[pos]) != -1) ? (DP(pos + 1, tim - a[pos + 1] + a[pos]) + a[pos + 1] - a[pos]) : -1;
	upd(ans, ansl), upd(ans, ansr);
	vis[pos][tim] = 1;
	return ans;
}
*/

struct ele{
	int pos, tim, d;
	bool operator < (const ele b) const{	
		return d < b.d;
	}
	ele(int pos, int tim, int d) : pos(pos), tim(tim), d(d){}
	ele(){}
};

int d[maxm][maxt];
bool vis[maxm][maxt]; 
priority_queue<ele> pq;
int Dij(){
	pq.push(ele(1, g, 0));
	d[1][g] = 0;
	while (!pq.empty()){
		ele op = pq.top(); pq.pop(); 
		int pos = op.pos, tim = op.tim;
		if (-op.d != d[pos][tim] || pos == m) continue;
		int dd = -op.d;
		if (!tim) {
			if (!d[pos][g] || d[pos][g] > r + dd) d[pos][g] = r + dd, pq.push(ele(pos, g, -r-dd)); 
		} 
		
		if (pos > 1 && a[pos] - a[pos - 1] <= tim){
			int _pos = pos - 1, _tim = tim - a[pos] + a[pos - 1];
			if (!d[_pos][_tim] || d[_pos][_tim] > dd + a[pos] - a[pos - 1]) d[_pos][_tim] = dd + a[pos] - a[pos - 1], pq.push(ele(_pos, _tim, -(dd + a[pos] - a[pos - 1])));
		}
		if (pos < m && a[pos + 1] - a[pos] <= tim){
			int _pos = pos + 1, _tim = tim - a[pos + 1] + a[pos];
			if (!d[_pos][_tim] || d[_pos][_tim] > dd + a[pos + 1] - a[pos]) d[_pos][_tim] = dd + a[pos + 1] - a[pos], pq.push(ele(_pos, _tim, -(dd + a[pos + 1] - a[pos])));
		}
		//ll ansl = (pos > 1 && a[pos] - a[pos - 1] <= tim && DP(pos - 1, tim - a[pos] + a[pos - 1]) != -1) ? (DP(pos - 1, tim - a[pos] + a[pos - 1]) + a[pos] - a[pos - 1]) : -1;
		//ll ansr = (pos < m && a[pos + 1] - a[pos] <= tim && DP(pos + 1, tim - a[pos + 1] + a[pos]) != -1) ? (DP(pos + 1, tim - a[pos + 1] + a[pos]) + a[pos + 1] - a[pos]) : -1;
		//upd(ans, ansl), upd(ans, ansr);
		//vis[pos][tim] = 1;
		//return ans;
	}
	int ans = -1;
	rep(i, 0, g) if (d[m][i]) ans = (ans == -1) ? d[m][i] : min(ans, d[m][i]); 
	return ans;
}

int main(){
	
		//freopen("c.in", "r", stdin);
		
	read(n), read(m);
	rep(i, 1, m) read(a[i]);
	sort(a + 1, a + 1 + m);
	read(g), read(r);
	printf("%d", Dij());
	//printf("%lld", DP(1, g));
	//write(DP(1, g));
	return 0;
}