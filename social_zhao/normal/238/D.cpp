#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, q, in[N][10], ou[N][10], tin[N], tou[N], tim, pre[N], suf[N], fa[N];
char s[N];
int pos, cnt[10], delt;

void erase(int x) { suf[pre[x]] = suf[x], pre[suf[x]] = pre[x]; }
int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

void init(int st) {
	pos = st, delt = 1;
	while(pos <= n) {
		int nxt;
		if(isdigit(s[pos])) {
			++cnt[s[pos] - '0'];
			if(s[pos] == '0') erase(pos);
			else --s[pos];
			nxt = delt > 0? suf[pos] : pre[pos];
		}
		else {
			if(s[pos] == '<') delt = -1;
			else delt = 1;
			nxt = delt > 0? suf[pos] : pre[pos];
			if(pos && !isdigit(s[nxt])) erase(pos);
		}
		if(delt > 0 && !tin[nxt]) {
			tin[nxt] = 1;
			for(int i = 0; i < 10; i++) in[nxt][i] = cnt[i];
		}
		if(delt < 0) {
			int der = find(nxt) + 1;
			while(der <= pos) {
				tou[der] = 1;
				for(int i = 0; i < 10; i++) ou[der][i] = cnt[i];
				fa[der - 1] = der, der = find(der) + 1;
			}
		}
		pos = nxt;
	}
}

int main() {
	n = get(), q = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) tin[i] = tou[i] = 0, fa[i] = i;
	for(int i = 0; i <= n; i++) pre[i] = i - 1, suf[i] = i + 1;
	while(suf[0] != n + 1 && pos <= n)
		init(0);
	for(int i = 1; i <= q; i++) {
		int l = get(), r = get();
		if(!tou[l]) 
			for(int i = 0; i < 10; i++) printf("%d ", in[r + 1][i] - in[l][i]); 
		else 
			for(int i = 0; i < 10; i++) printf("%d ", min(ou[l][i], in[r + 1][i]) - in[l][i]);
		printf("\n");
	}
	return 0;
}