#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, m, q;
char lft[N], rht[N], up[N], dwn[N];
struct Node { int x, y; } bin[N];
int top;
int f[N][2];

void push(int x, int y) { bin[++top] = (Node){ x, y }; }
int GetDis(Node x, Node y) { return abs(x.x - y.x) + abs(x.y - y.y); }

int solve() {
	f[0][0] = f[0][1] = 0;
	for(int i = 1; i <= n; i++) f[0][0] += lft[i] == 'R', f[0][1] += lft[i] == 'B';
	for(int i = 1; i <= m; i++) {
		f[i][0] = min(f[i - 1][0], f[i - 1][1] + n) + (up[i] == 'R') + (dwn[i] == 'R');
		f[i][1] = min(f[i - 1][1], f[i - 1][0] + n) + (up[i] == 'B') + (dwn[i] == 'B');
	}
	int res = 0x3f3f3f3f;
	int now = f[m][0];
	for(int i = 1; i <= n; i++) now += rht[i] == 'R';
	res = min(res, now);
	now = f[m][1];
	for(int i = 1; i <= n; i++) now += rht[i] == 'B';
	res = min(res, now);
	return res;
}

int main() {
	n = get(), m = get(), q = get();
	scanf("%s", lft + 1);
	scanf("%s", rht + 1);
	scanf("%s", up + 1);
	scanf("%s", dwn + 1);
	int ans = 0x3f3f3f3f;
	ans = min(ans, solve());
	swap(n, m);
	swap(lft, up), swap(rht, dwn);
	ans = min(ans, solve());
	cout << ans << endl;
	return 0;
}

/*
3 6 0
RBR
BRB
RRRBBB
RRRBBB

2 2 0
RR
RB
BB
RB
*/