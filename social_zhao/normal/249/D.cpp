#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a, b, c, d, binx[N], biny[N], lenx, leny, f[N];
struct Node { int x, y; Node(int a = 0, int b = 0) { x = a, y = b; } } p[N];
vector<Node> bin[N];

int sum[N];
int lowbit(int x) { return x & (-x); }
void add(int x, int v) { while(x) sum[x] = max(sum[x], v), x -= lowbit(x); }
int ask(int x) { int r(0); while(x <= n) r = max(r, sum[x]), x += lowbit(x); return r; }

main() {
	n = get(), a = get(), b = get(), c = get(), d = get();
	for(int i = 1, x, y; i <= n; i++) 
		x = get(), y = get(), p[i] = Node(c * x - d * y, b * y - a * x), binx[i] = p[i].x, biny[i] = p[i].y;
	p[++n] = Node(0, 0);
	sort(binx + 1, binx + 1 + n), sort(biny + 1, biny + 1 + n);
	lenx = unique(binx + 1, binx + 1 + n) - binx - 1, leny = unique(biny + 1, biny + 1 + n) - biny - 1;
	for(int i = 1; i <= n; i++) {
		p[i].x = lower_bound(binx + 1, binx + 1 + lenx, p[i].x) - binx;
		p[i].y = lower_bound(biny + 1, biny + 1 + leny, p[i].y) - biny;
		bin[p[i].x].emplace_back(p[i].y, i);
	}
	for(int i = n; i >= 1; i--) {
		for(auto v : bin[i]) f[v.y] = ask(v.x + 1) + 1;
		for(auto v : bin[i]) add(v.x, f[v.y]); 
	}
	for(int i = 1; i <= n; i++) 
		if(binx[p[i].x] == 0 && biny[p[i].y] == 0) 
			cout << f[i] - 1 << endl;
	return 0;
}