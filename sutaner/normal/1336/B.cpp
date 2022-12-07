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
#define maxn 400020
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
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
}

int n, m, p;
vector<int> v[3];
pii lis[maxn]; 
int mx[3];

int main(){
	
		//freopen("b.in", "r", stdin);

	int T, x;
	read(T);
	rep(TT, 1, T){
		int cs = 0;
		rep(i, 0, 2) v[i].clear(), mx[i] = 0;
		read(n), read(m), read(p);
		rep(i, 1, n) read(x), lis[++cs] = pii(x, 0), v[0].pb(x << 1), mx[0] = max(mx[0], x);
		rep(i, 1, m) read(x), lis[++cs] = pii(x, 1), v[1].pb(x << 1), mx[1] = max(mx[1], x);
		rep(i, 1, p) read(x), lis[++cs] = pii(x, 2), v[2].pb(x << 1), mx[2] = max(mx[2], x);
		sort(lis + 1, lis + 1 + cs);
		rep(i, 0, 2) sort(v[i].begin(), v[i].end());
		/*
		rep(i, 1, cs) {
			rep(j, 0, 2) num[i][j] = num[i - 1][j];
			num[i][lis[i].se]++;
		}
		*/
		ll ans = -1;
		int ptr = 1;
		rep(i, 1, cs){	
			int cx = lis[i].se;
			while (i + 1 <= cs && lis[i + 1].se == cx) i++;
			int x = lis[i].fi, y = -1, cy = -1, z = -1, cz = -1;
			rep(j, 0, 2){
				if (j == cx) continue;
				if (y == -1) {
					if (x > mx[j]) goto over;
					y = (*lower_bound(v[j].begin(), v[j].end(), x << 1)) >> 1;
					cy = j;
				}
				else {
					if (x > mx[j]) goto over;
					z = (*lower_bound(v[j].begin(), v[j].end(), x << 1)) >> 1;
					cz = j;
				}
			}
			if (z < y) swap(y, z), swap(cy, cz);
			vector<int> :: iterator it = lower_bound(v[cy].begin(), v[cy].end(), (x + z));
			if (it == v[cy].end()){
				--it;
				y = (*it) >> 1;
			}
			else {
				if (((*it) >> 1) <= z) y = (*it) >> 1;
				if (it != v[cy].begin()){
					--it;
					if (*it >= x && (abs(x + z - *it) < abs((y << 1) - x - z))) y = (*it) >> 1;
				} 
			}
			ll res = (ll)(x - y) * (x - y) + (ll)(y - z) * (y - z) + (ll)(z - x) * (z - x);
			ans = (ans == -1) ? res : min(ans, res);
			/*
			ptr = max(ptr, i);
			int x = lis[i].fi;
			while (ptr <= cs 
				&& (num[ptr][0] - num[i - 1][0] == 0
				|| num[ptr][1] - num[i - 1][1] == 0
				|| num[ptr][2] - num[i - 1][2] == 0)) ptr++; 
			*/
		}
		over: write(ans);
		if (TT != T) putchar('\n'); 
	}
	return 0;
}