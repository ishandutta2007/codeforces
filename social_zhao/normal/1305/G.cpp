#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, Base = 1 << 18;
int n, a[N], fa[N], ans, cnt;
pair<int, int> bel[N];

int find(int x) { if(x == -1) return -1; return x == fa[x]? x : fa[x] = find(fa[x]); }

struct Node {
	pii fir, sec;
	Node() { fir = sec = make_pair(-1, -1); }
	void insert(pii x) {
		if(x.first > fir.first) {
			if(find(fir.second) == find(x.second)) fir = x;
			else sec = fir, fir = x;
		}
		else if(x.first > sec.first) {
			if(find(x.second) != find(fir.second)) sec = x;
		}
	}
	Node operator +(Node b) { Node res = b; res.insert(fir), res.insert(sec); return res; }
} f[Base];

void FMT() {
	for(int i = 1; i <= 18; i++)
		for(int j = 0; j < Base; j++)
			if(j >> (i - 1) & 1) 
				f[j] = f[j] + f[j ^ (1 << (i - 1))];
}

void Boruvka() {
	for(int i = 0; i < Base; i++) f[i] = Node();
	for(int i = 0; i <= n; i++) f[a[i]].insert(make_pair(a[i], find(i))), bel[i] = make_pair(0, -1);
	FMT();
	for(int i = 0; i <= n; i++) {
		Node mx = f[(Base - 1) ^ a[i]];
		if(mx.fir.second != -1 && find(mx.fir.second) != find(i))
			bel[find(i)] = max(bel[find(i)], make_pair(a[i] + mx.fir.first, mx.fir.second));
		else if(mx.sec.second != -1 && find(mx.sec.second) != find(i))
			bel[find(i)] = max(bel[find(i)], make_pair(a[i] + mx.sec.first, mx.sec.second));
	}
	for(int i = 0; i <= n; i++) 
		if(bel[i].second != -1 && find(i) != find(bel[i].second)) 
			--cnt, fa[find(i)] = find(bel[i].second), ans += bel[i].first;
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), ans -= a[i];
	for(int i = 0; i <= n; i++) fa[i] = i;
	cnt = n + 1;
	while(cnt > 1) Boruvka();
	cout << ans;
	return 0;
}

/*
5
4 3 1 2 15 
*/