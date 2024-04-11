#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, inf = 100000;
int n, tot, top;
struct Vector {
	int x, y;
	Vector() { x = y = 0; }
	Vector(int a, int b) { x = a, y = b; }
	Vector operator +(Vector b) { return Vector(x + b.x, y + b.y); }
	Vector operator -(Vector b) { return Vector(x - b.x, y - b.y); } 
	bool operator ==(Vector b) { return x == b.x && y == b.y; }
	int operator *(Vector b) { return x * b.x + y * b.y; }
	int operator &(Vector b) { return x * b.y - y * b.x; }
	double len() { return sqrt(x * x + y * y); }
} p[N], st[N];

void push(int x, int y) { p[++tot] = Vector(x, y); }

void ConvexHull() {
	for(int i = 2; i <= tot; i++) if(p[i].x < p[1].x || (p[i].x == p[1].x && p[i].y < p[1].y)) swap(p[1], p[i]);
	sort(p + 2, p + 1 + tot, [](Vector a, Vector b) { 
		int t = ((a - p[1]) & (b - p[1]));
		return (t == 0)? (a.len() < b.len()) : (t > 0);
	});
	st[top = 1] = p[1];
	for(int i = 2; i <= tot; i++) {
		if(p[i] == p[i - 1]) continue;
		while(top > 1 && ((st[top] - st[top - 1]) & (p[i] - st[top])) <= 0) --top;
		st[++top] = p[i];
	}
}

double GetR(Vector a, Vector b, Vector c) {
	return 1.0 * (a - b).len() * (b - c).len() * (a - c).len() / (2 * abs((a - b) & (a - c)));
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		int x = get(), y = get(), v = get();
		
		if(x - v >= 0) push(x - v, y);
		else push(0ll, max(0ll, y - (v - x))), push(0ll, min(inf, y + (v - x)));
		if(y - v >= 0) push(x, y - v);
		else push(max(0ll, x - (v - y)), 0ll), push(min(inf, x + (v - y)), 0ll);
		if(x + v <= inf) push(x + v, y);
		else push(inf, max(0ll, y - (v - (inf - x)))), push(inf, min(inf, y + (v - (inf - x))));
		if(y + v <= inf) push(x, y + v);
		else push(max(0ll, x - (v - (inf - y))), inf), push(min(inf, x + (v - (inf - y))), inf);
	}
	
	ConvexHull();
	
	double mx = 0;
	int mi, mj, mk;
	for(int i = 1; i <= top; i++) {
		int j = i % top + 1, k = j % top + 1;
		if(GetR(st[i], st[j], st[k]) > mx) 
			mx = GetR(st[i], st[j], st[k]), mi = i, mj = j, mk = k;
	}
	
	printf("%d %d\n%d %d\n%d %d\n", st[mi].x, st[mi].y, st[mj].x, st[mj].y, st[mk].x, st[mk].y);
	return 0;
}