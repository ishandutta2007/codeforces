#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

struct Heap {
	priority_queue<int> a, b;

	void pre() { while(a.size() && b.size() && a.top() == b.top()) a.pop(), b.pop(); }
	int top() { pre(); return a.top(); }
	void del(int x) { pre(); b.push(x); }
	void push(int x) { a.push(x); }
	bool empty() { pre(); return a.empty(); }
} g;

int gcd(int x, int y) {
	if(!y) return x;
	return gcd(y, x % y);
}

int n, a[505], top, _gcd;

int main() {
	n = get();
	for(int i = 1; i <= n * n; i++) g.push(get());
	while(!g.empty()) {
		int x = g.top(); g.del(x);
		a[++top] = x;
		for(int i = 1; i <= top - 1; i++) 
			g.del(_gcd = gcd(a[i], a[top])), g.del(_gcd);
	}
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}