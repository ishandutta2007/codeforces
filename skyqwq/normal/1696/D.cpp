// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 250005, S = N * 19 * 4, INF = 1e9;


int n, a[N], q[N], Ln[N], Rn[N], Rm[N], Lm[N], s[N], top, d[N];

void inline bfs() {
	int hh = 0, tt = 0;
	for (int i = 1; i <= n; i++) d[i] = INF;
	q[0] = 1; d[1] = 0;
	while (hh <= tt) {
		int u = q[hh++];
		int x = Ln[u];
		while (x && x > Lm[u]) {
			if (d[u] + 1 < d[x]) {
				d[x] = d[u] + 1;
				q[++tt] = x;
			} else break;
			x = Ln[x];
		}
		x = Lm[u];
		while (x && x > Ln[u]) {
			if (d[u] + 1 < d[x]) {
				d[x] = d[u] + 1;
				q[++tt] = x;
			} else break;
			x = Lm[x];
		}

		x = Rn[u];
		while (x <= n && x < Rm[u]) {
			if (d[u] + 1 < d[x]) {
				d[x] = d[u] + 1;
				q[++tt] = x;
			} else break;
			x = Rn[x];
		}
		x = Rm[u];
		while (x <= n && x < Rn[u]) {
			if (d[u] + 1 < d[x]) {
				d[x] = d[u] + 1;
				q[++tt] = x;
			} else break;
			x = Rm[x];
		}
	}
	printf("%d\n", d[n]);
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n); 
    	for (int i = 1; i <= n; i++) read(a[i]);
    	s[0] = 0;
    	top = 0;
    	for (int i = 1; i <= n; i++) {
    		while (top && a[s[top]] >= a[i]) top--;
    		Ln[i] = s[top];
    		s[++top] = i;
    	}
    	top = 0;
    	for (int i = 1; i <= n; i++) {
    		while (top && a[s[top]] <= a[i]) top--;
    		Lm[i] = s[top];
    		s[++top] = i;
    	}
    	s[0] = n + 1;
    	top = 0;
    	for (int i = n; i; i--) {
    		while (top && a[s[top]] >= a[i]) top--;
    		Rn[i] = s[top];
    		s[++top] = i;
    	}
    	top = 0;
    	for (int i = n; i; i--) {
    		while (top && a[s[top]] <= a[i]) top--;
    		Rm[i] = s[top];
    		s[++top] = i;
    	}
    	bfs();
    }
    return 0;
}