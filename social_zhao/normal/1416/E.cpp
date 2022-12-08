#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, a[N];
struct Node {
	int l, r;
	Node(int a = 0, int b = 0) { if(a > b) swap(a, b); l = a, r = b; }
	bool operator <(Node b) const { return l < b.l; }
};
set<Node> s;
int mn, A, B;

Node bin[N];
int top;
void Debug() {
	top = 0;
	for(auto v : s) bin[++top] = Node(A * v.l + B, A * v.r + B);
	for(int i = 1; i <= top; i++) if(bin[i].l > bin[i].r) swap(bin[i].l, bin[i].r);
	cout << mn << ": "; for(int i = 1; i <= top; i++) cout << "[" << bin[i].l << "," << bin[i].r << "]" << " "; cout << endl;
}

void pushtag(int a, int b) { A *= a, B *= a, B += b; }
int GetOri(int x) { return (x - B) / A; }

int inset(int x) { 
	x = GetOri(x);
	set<Node>::iterator it = s.upper_bound(Node(x, x));
	if(it == s.begin()) return 0;
	--it;
	return x <= (it -> r);
}

void maintain(int L, int R) {
	L = GetOri(L), R = GetOri(R);
	if(L > R) swap(L, R);
	while(s.size()) {
		Node x = *s.begin();
		if(L <= x.l && x.r <= R) break;
		s.erase(x), x.l = max(x.l, L), x.r = min(x.r, R);
		if(x.l <= x.r) s.insert(x);
	}
	while(s.size()) {
		Node x = *s.rbegin();
		if(L <= x.l && x.r <= R) break;
		s.erase(x), x.l = max(x.l, L), x.r = min(x.r, R);
		if(x.l <= x.r) s.insert(x);
	}
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	s.clear(), A = 1, B = 0;
	if(a[1] & 1) s.insert(Node(1, a[1] - 1)), mn = 2;
	else s.insert(Node(a[1] / 2, a[1] / 2)), mn = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] % 2 == 0 && inset(a[i] / 2)) { s.clear(), A = 1, B = 0, s.insert(Node(a[i] / 2, a[i] / 2)); continue; }
		pushtag(-1, a[i]);
		maintain(1, a[i] - 1);
		if(a[i] % 2 == 0) {
			if(!inset(a[i] / 2)) s.insert(Node(GetOri(a[i] / 2), GetOri(a[i] / 2)));
		}
		if(s.empty()) A = 1, B = 0, s.insert(Node(1, a[i] - 1)), mn += 2;
		else ++mn;
//		cout << i << endl;
//		Debug();
	}
	cout << mn << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
4 5 3 3
*/