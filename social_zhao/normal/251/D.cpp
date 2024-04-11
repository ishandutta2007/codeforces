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
int n, a[N], sum, id[N], b[N], x1, res[N]; 
bitset<N> m[65];

void insert(int x) {
	for(int i = 0; i <= 60; i++) {
		if(!(x >> id[i] & 1)) continue;
		if(!b[id[i]]) { b[id[i]] = x; break; }
		else x ^= b[id[i]];
	}
}

void Gauss() {
	for(int i = 1; i <= 61; i++) {
		int p = 0, mp = 0x3f3f3f3f;
		for(int j = i; j <= 61; j++) {
			if(!m[j].count()) continue;
			int fir = m[j]._Find_first();
			if(fir < mp) mp = fir, p = j;
		}
		if(mp == 0x3f3f3f3f) break;
		swap(m[i], m[p]);
		for(int j = 1; j <= 61; j++) {
			if(i == j) continue;
			if(m[j][mp]) m[j] = m[j] ^ m[i];
		}
	}
}

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), sum ^= a[i];
	for(int i = 0; i <= 60; i++) id[i] = i;
	sort(id, id + 1 + 60, [](int x, int y) { return ((sum >> x & 1) == (sum >> y & 1))? x > y : ((sum >> x & 1) < (sum >> y & 1)); });
	for(int i = 1; i <= n; i++) insert(a[i]);
	for(int i = 0; i <= 60; i++) {
		if(!(sum >> id[i] & 1) && !(x1 >> id[i] & 1)) 
			x1 ^= b[id[i]];
		if((sum >> id[i] & 1) && (x1 >> id[i] & 1)) 
			x1 ^= b[id[i]];
	}
	for(int i = 1; i <= 61; i++)
		for(int j = 1; j <= n; j++)
			if(a[j] >> (i - 1) & 1) m[i].set(j);
	for(int i = 1; i <= 61; i++) if(x1 >> (i - 1) & 1) m[i].set(n + 1);
	Gauss();
	for(int i = 1; i <= n; i++) res[i] = 2;
	for(int i = 1; i <= 61; i++) {
		if(!m[i].count()) continue;
		int fir = m[i]._Find_first(), ans = m[i][n + 1];
		if(ans) res[fir] = 1;
	}
	for(int i = 1; i <= n; i++) printf("%d ", res[i]);
	return 0;
}