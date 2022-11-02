#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 30;

int n;
int c[N], life[N], a[N], cnt[N], id[N];

inline int ask(int x) {
	int nowans = n + 1;
	for(; x; x -= x & -x)nowans = min(nowans, c[x]);
	return nowans;
}

inline void add(int x, int v) {
	for(; x <= n; x += x & -x)c[x] = min(c[x], v);
}

inline int ask1(int x) {
	int nowans = 0;
	for(; x; x -= x & -x)nowans = max(nowans, c[x]);
	return nowans;
}

inline void add1(int x, int v) {
	for(; x <= n; x += x & -x)c[x] = max(c[x], v);
}


inline int cmp(int x, int y) {
	return life[x] < life[y];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), c[i] = n + 1, id[i] = i, cnt[i] = 0;;
		for(int i = n; i; i--) {
			life[i] = ask(a[i] - 1) - i;
			add(a[i], i); 
			cnt[a[i]]++;
		}
		cnt[n + 1] = 0;
		for(int i = 1; i <= n; i++)
			c[i] = 0;
		for(int i = 1; i <= n; i++) {
			life[i] += i - ask1(a[i]) - 1;
			add1(a[i], i);
		}
		sort(id + 1, id + 1 + n, cmp);
		int l = 1, nowmin = 0, sumn = n;
		for(int i = 1; i <= n + 1; i++)
			if(!cnt[i]) {
				nowmin = i;
				break;
			}
		for(int i = 1; i <= n; i++) {
			while(life[id[l]] < i && l <= n) {
				cnt[a[id[l]]]--, sumn--;
				if(!cnt[a[id[l]]])nowmin = min(nowmin, a[id[l]]);
				l++;
			}
			if(n - i + 1 != nowmin - 1 || nowmin <= n - i + 1) {
				putchar('0');
			}
			else putchar('1');
		}
		puts("");
	}
}