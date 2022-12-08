#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, q, tag[N];

int sum[N];
int lowbit(int x) { return x & (-x); }
void add(int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
void add(int l, int r, int v) { add(l, v), add(r + 1, -v); }

struct Node {
	int l, r, c;
	bool operator <(Node b) const { return l < b.l; }
	Node(int x = 0, int y = 0, int z = 0) { l = x, r = y, c = z; }
};
set<Node> s;

set<Node>::iterator split(int x) {
	set<Node>::iterator it = s.lower_bound(Node(x));
	if(it != s.end() && it -> l == x) return it;
	--it;
	int l = it -> l, r = it -> r, v = it -> c;
	s.erase(it), s.insert(Node(l, x - 1, v));
	return s.insert(Node(x, r, v)).first;
}

void Debug() {
	for(set<Node>::iterator it = s.begin(); it != s.end(); ++it) cout << "[" << it -> l << "," << it -> r << "," << it -> c << "]\n";
	cout << endl;
	for(int i = 1; i <= n; i++) cout << ask(i) << " "; cout << endl;
}

void color(int l, int r, int x) {
	set<Node>::iterator itr = split(r + 1), itl = split(l);
	for(set<Node>::iterator it = itl; it != itr; ++it) add(it -> l, it -> r, tag[it -> c] - tag[x]);
	s.erase(itl, itr);
	s.insert(Node(l, r, x));
}

int GetCol(int x) {
	set<Node>::iterator it = s.upper_bound(Node(x)); --it;
	return it -> c;
}

 main() {
	n = get(), q = get();
	s.insert(Node(1, n, 1));
	for(int i = 1; i <= q; i++) {
		char opt[10]; int l, r, x;
		scanf("%s", opt);
		if(opt[0] == 'C') l = get(), r = get(), x = get(), color(l, r, x);
		if(opt[0] == 'A') l = get(), r = get(), tag[l] += r;
		if(opt[0] == 'Q') x = get(), printf("%lld\n", ask(x) + tag[GetCol(x)]);
//		Debug();
	}
	return 0;
}