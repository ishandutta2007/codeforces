// Problem: A2. Burenka and Traditions (hard version)
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/A2
// Memory Limit: 256 MB
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
const int N = 1e5+5;

int T, n, a[N], s[N];
map<int, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) s[i] = s[i-1] ^ a[i];
		mp.clear();
		mp[0] = 0;
		int now = 0, diff = 0;
		rep(i, 1, n) {
			if(mp.find(s[i]) != mp.end() && mp[s[i]] >= now) {
				++diff;
				now = i;
			}
			mp[s[i]] = i;
		}
		printf("%d\n", n-diff);
	}
	return 0;
}