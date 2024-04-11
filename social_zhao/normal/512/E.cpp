#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e3 + 5;
int n;
int a[N], b[N];
int x[N], y[N], top, tot, u[N], v[N], edge[N][N];
priority_queue< pair<int, int> > q;

void getinv(int u, int v, int &p1, int &p2) {
	p1 = p2 = 0;
	for(int i = 1; i <= n; i++) {
		if(edge[u][i] && edge[i][v]) {
			if(p1) p2 = i;
			else p1 = i;
		}
	}
}

int main() {
	n = get();
	for(int i = 1; i < n; i++) edge[i][i + 1] = edge[i + 1][i] = 1;
	edge[1][n] = edge[n][1] = 1;
	for(int i = 1; i <= n - 3; i++) {
		a[i] = get(), b[i] = get();
		if(a[i] != 1 && b[i] != 1) q.push(make_pair(abs(a[i] - b[i]), i));
	}
	while(q.size()) u[++tot] = a[q.top().second], v[tot] = b[q.top().second], q.pop();
	for(int i = 1; i <= n - 3; i++) {
		a[i] = get(), b[i] = get();
		edge[a[i]][b[i]] = edge[b[i]][a[i]] = 1;
		if(a[i] != 1 && b[i] != 1) q.push(make_pair(abs(a[i] - b[i]), i));
	}
	while(q.size()) {
		int un = a[q.top().second], vn = b[q.top().second]; q.pop();
		int xn, yn;
		getinv(un, vn, xn, yn);
		x[++top] = xn, y[top] = yn;
		edge[un][vn] = edge[vn][un] = 0, edge[xn][yn] = edge[yn][xn] = 1;
	}
	while(top) u[++tot] = x[top], v[tot] = y[top], top--;
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++) printf("%d %d\n", u[i], v[i]);
	return 0;
}