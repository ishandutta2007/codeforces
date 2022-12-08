#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, nxt[N], vis[N], col, rt[N], shit;
int q, x[N], y[N];

void push(int a, int b) { ++q, x[q] = a, y[q] = b; }

void solve1(int cira, int cirb) {
	int rta = rt[cira], rtb = rt[cirb];
	push(rta, rtb);
	swap(nxt[rta], nxt[rtb]);
	while(nxt[rta] != rtb) {
		int lst = nxt[rta];
		push(lst, rta), swap(nxt[rta], nxt[lst]);
	}
	while(nxt[rtb] != rta) {
		int lst = nxt[rtb];
		push(lst, rtb), swap(nxt[rtb], nxt[lst]);
	}
	push(rta, rtb), swap(nxt[rta], nxt[rtb]);
	shit = rta;
}

void solve2(int cir) {
	int rtn = rt[cir], lop = nxt[rtn];
	if(nxt[nxt[rtn]] == rtn) {
		push(rtn, shit), swap(nxt[rtn], nxt[shit]);
		push(shit, lop), swap(nxt[shit], nxt[lop]);
		push(rtn, shit), swap(nxt[rtn], nxt[shit]);
		return;
	}
	push(rtn, lop), swap(nxt[rtn], nxt[lop]);
	while(nxt[nxt[rtn]] != rtn) {
		int lst = nxt[rtn];
		push(rtn, lst), swap(nxt[rtn], nxt[lst]);
	}
	int b = nxt[rtn];
	push(b, lop), swap(nxt[b], nxt[lop]);
	push(rtn, b), swap(nxt[rtn], nxt[b]);
	push(rtn, lop), swap(nxt[rtn], nxt[lop]);
}

void print() {
	printf("%d\n", q);
	for(int i = 1; i <= q; i++) printf("%d %d\n", x[i], y[i]);
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) nxt[i] = get();
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		if(nxt[i] == i) { vis[i] = -1; shit = i; continue; }
		++col, rt[col] = i, vis[i] = col;
		int now = i;
		while(nxt[now] != i) vis[nxt[now]] = col, now = nxt[now];
	}
	for(int i = 1; i <= n; i++) assert(vis[i] != 0), assert(nxt[i] != 0);
	for(int i = 1; i + 1 <= col; i += 2) solve1(i, i + 1);
	if(col & 1) solve2(col);
	print();
	return 0;
}

/*
4
2 3 4 1
*/