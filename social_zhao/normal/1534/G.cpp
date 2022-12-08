#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 8e5 + 5;
int n, bin[N];
struct Node { int x, y; } p[N];

namespace Convex {
	int k, b, tag;
	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<int> > q2;
	
	void maintain() { //  
		while(q1.size() + k > 0) {
			int u = q1.top();
			q2.push(u - tag), q1.pop();
		}
		while(q2.size() && q1.size() && q2.top() + tag < q1.top()) {
			int u = q1.top(), v = q2.top() + tag;
			q1.pop(), q2.pop(), q1.push(v), q2.push(u - tag);
		}
	}
	
	void MoveRight(int delta) { //  delta 
		if(q2.size()) tag += delta;
	}
	
	void Insert(int x0) { //  f(x) = |x - x0|
		k--, b += x0, q1.push(x0), q1.push(x0);
		maintain();
	}
}

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) p[i].x = get(), p[i].y = get();
	sort(p + 1, p + 1 + n, [](Node a, Node b) { return a.x + a.y < b.x + b.y; });
	for(int i = 1; i <= n; i++) {
		Convex::MoveRight(p[i].x + p[i].y - p[i - 1].x - p[i - 1].y);
		Convex::Insert(p[i].x);
	}
	int lstx = 0, lsty = Convex::b, nowk = Convex::k, ans = lsty, sze = Convex::q1.size(); 
	while(Convex::q1.size()) {
		int x = Convex::q1.top();
		bin[Convex::q1.size()] = x; 
		Convex::q1.pop();
	}
	for(int i = 1; i <= sze; i++) {
		int x = bin[i];
		lsty += (x - lstx) * nowk, nowk++, lstx = x;
		ans = min(ans, lsty);
	}
	printf("%lld\n", ans);
	return 0;
}