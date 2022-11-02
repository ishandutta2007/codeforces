#include<bits/stdc++.h>

#define INF 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
using namespace std;

typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

#define NN 300011
pii w[NN], h[NN];
INT val[NN][4];
int p[NN];
INT dp[NN];

int solve() {
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		gn(w[i].x);
		w[i].y = i;
	}
	for(int i=1; i<=n; i++) {
		gn(h[i].x);
		p[i] = i;
		h[i].y = i;
	}
	sort(w+1, w+n+1);
	sort(h+1, h+n+1);
	reverse(w+1, w+n+1);
	reverse(h+1, h+n+1);
	for(int i=1; i<=n; i++) {
		val[i][0] = (INT)h[i].x * w[i].x;
		val[i][1] = (INT)h[i].x * w[i-1].x + (INT)h[i-1].x * w[i].x;
		if(i>2) {
			val[i][2] = (INT)h[i].x * w[i-1].x +  (INT)h[i-1].x * w[i-2].x + (INT)h[i-2].x * w[i].x;
			INT tmp=(INT)w[i].x*h[i-1].x+(INT)w[i-1].x*h[i-2].x+(INT)w[i-2].x*h[i].x;
			if(tmp > val[i][2]) val[i][2] = tmp;
		}
	}
	int u, v;
	while(q--) {
		gn(u); gn(v);
		swap(p[u], p[v]);
		INT ans=-INF, tmp;
		for(int i=1; i<=n; i++) {
			dp[i] = -INF;
			if(p[w[i].y] != h[i].y) {
				dp[i] = dp[i-1] + val[i][0];
			}
			if(i>1) {
				tmp = val[i][1] + dp[i-2];
				if(tmp>dp[i]) dp[i] = tmp;
			}
			if(i>2) {
				tmp=val[i][2] + dp[i-3];
				if(tmp > dp[i]) dp[i] = tmp;
			}
		}
		println(dp[n]);
	}
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}