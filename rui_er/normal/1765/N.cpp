// LUOGU_RID: 96019970
// Problem: N. Number Reduction
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/N
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n, k, nxt[N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%s%d", s+1, &k);
		n = strlen(s+1);
		nxt[n+1] = 0;
		per(i, n, 1) nxt[i] = s[i] == 48 ? nxt[i+1] : i;
		int start = 1;
		rep(i, 2, k+1) if(s[i] != 48 && s[i] < s[start]) start = i;
		k -= start - 1;
		stack<int> stk, tmp;
		rep(i, start, n) {
			int c = s[i] ^ 48;
			while(!stk.empty() && c < stk.top() && k > 0) {
				if((int)stk.size() == 1 && !c) break;
				stk.pop();
				--k;
			}
			stk.push(c);
		}
		for(; !stk.empty(); stk.pop()) {
			if(k) --k;
			else tmp.push(stk.top());
		}
		for(; !tmp.empty(); tmp.pop()) putchar(tmp.top() ^ 48);
		puts("");
	}
	return 0;
}