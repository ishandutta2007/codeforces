#include<bits/stdc++.h>
using namespace std;

inline int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4000005;
int Q;
int ch[N][2], tot = 1, cnt[N];

inline void insert(int x, int tp) {
	int now = 1;
	for(register int i = 27; i >= 0; i--) {
		bool c = x & (1 << i);
		if(!ch[now][c]) ch[now][c] = ++tot;
		now = ch[now][c], cnt[now] += tp;
	}
}

inline int query(int p, int l) {
	int now = 1, ans = 0;
	for(register int i = 27; i >= 0; i--) {
		bool c1 = p & (1 << i), c2 = l & (1 << i);
		if(c2) ans += cnt[ch[now][c1]];
		now = ch[now][c1 ^ c2];
	}
	return ans;
}

int main() {
	Q = get();
	while(Q--) {
		int opt = get(), p = get();
		if(opt == 1) insert(p, 1);
		else if(opt == 2) insert(p, -1);
		else printf("%d\n", query(p, get()));
	}
	return 0;
}