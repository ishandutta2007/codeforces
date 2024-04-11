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
int n;
char s[N], t[N], der[N];
int suf[N], pos[26];

namespace BIT {
	int sum[N];
	
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
	void init(int n) { for(int i = 0; i <= n; i++) sum[i] = 0; }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
}

int JudgeImpossible() {
	for(int i = 1; i <= n; i++) der[i] = s[i];
	sort(der + 1, der + 1 + n);
	for(int i = 1; i <= n; i++) if(der[i] != t[i]) return der[i] < t[i];
	return 0;
}

void solve() {
	n = get();
	scanf("%s", s + 1), scanf("%s", t + 1);
	int State = JudgeImpossible();
	if(!State) return printf("-1\n"), void(); 
	for(int i = 0; i < 26; i++) pos[i] = n + 1;
	for(int i = n; i >= 1; i--) 
		suf[i] = pos[s[i] - 'a'], pos[s[i] - 'a'] = i;
	BIT::init(n);
	for(int i = 1; i <= n; i++) BIT::add(i, 1);
	int nw = 0, ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		int mn = 0x3f3f3f3f3f3f3f3f;
		for(int j = 0; j < t[i] - 'a'; j++) 
			if(pos[j] <= n) 
				mn = min(mn, BIT::ask(pos[j] - 1));
		ans = min(ans, nw + mn);
		if(pos[t[i] - 'a'] > n) break;
		nw += BIT::ask(pos[t[i] - 'a'] - 1);
		BIT::add(pos[t[i] - 'a'], -1);
		pos[t[i] - 'a'] = suf[pos[t[i] - 'a']];
	}
	printf("%lld\n", ans);
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
3
rll
rrr
*/