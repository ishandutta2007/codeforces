#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

bitset<1000> s0, s1, t1, t2, t3, t4, a, b;
bitset<1000> S[1024], tmp[1024];
int len, dep[1000], fa[1000];
char ss[1000];
int n;

bitset<1000> query(bitset<1000> hh, int dep) {
	if(!hh.count()) {
		for(int i = 0; i < n; i++) hh[i] = 0;
		return hh;
	} else if(dep == 0) return hh;
	putchar('?'), putchar(' ');
	for(int i = 0; i < n; i++) {
		if(hh[i]) put(dep), putchar(' ');
		else putchar('0'), putchar(' ');
	} puts(""); fflush(stdout);
	scanf("%s", ss);
	for(int i = 0; i < n; i++) hh[i] = hh[i] | (ss[i] == '1');
	return hh;
}

int main() {
	int k = 10; n = read();
	for(int i = 0; i < n; i++) S[0][i] = 1;
	s0[0] = 1; len = 1;
	while(k > 0) {
		k--;
		if((1 << k) >= n) continue;
		t1 = query(s0, 1 << k), t2 = query(s1, 1 << k), t3 = query(s0, (1 << k) - 1), t4 = query(s1, (1 << k) - 1);
		s0 = s0 | s1; s1.reset();
		for(int i = 0; i < len; i++) {
			if(!(i & 1)) a = S[i] & t1, b = S[i] & t3;
			else a = S[i] & t2, b = S[i] & t4;
			s1 |= a ^ b, tmp[2 * i] = b, tmp[2 * i + 1] = S[i] ^ tmp[2 * i];
		} len = 2 * len; int u = len - 1;
		while(!tmp[u].count()) len--, u--;
		for(int i = 0; i < len; i++) S[i] = tmp[i];
	} for(int i = 0; i < len; i++) for(int k = S[i]._Find_first(); k < n; k = S[i]._Find_next(k)) dep[k] = i;
	for(int x = 0; x < 3; x++) {
		int o = (x + 1) % 3;
		for(int i = 0; i < 10; i++) {
			if((1 << i) >= n) break;
			t1.reset();
			for(int j = x; j < len; j += 3) {
				for(int k = S[j]._Find_first(); k < n; k = S[j]._Find_next(k)) t1[k] = k >> i & 1;
			} t2 = query(t1, 1);
			for(int k = t2._Find_first(); k < n; k = t2._Find_next(k)) fa[k] += (dep[k] % 3 == o) ? (1 << i) : 0;
		}
	} puts("!");
	for(int i = 1; i < n; i++) put(fa[i] + 1), putchar(' '), put(i + 1), puts("");
	fflush(stdout);
	return 0;
}