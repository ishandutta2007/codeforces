// LUOGU_RID: 96019867
// Problem: B. Broken Keyboard
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
const int N = 105;

int T, n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%s", &n, s+1);
		bool ok = 1;
		for(int i = 1, rnd = 0; i <= n; rnd ^= 1) {
			if(!rnd) ++i;
			else {
				if(i == n || s[i] != s[i+1]) {
					ok = 0;
					break;
				}
				else i += 2;
			}
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}