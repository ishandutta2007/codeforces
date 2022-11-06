// LUOGU_RID: 91302046
// Problem: A1. Make Nonzero Sum (easy version)
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforc.es/contest/1753/problem/A1
// Memory Limit: 256 MB
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
const int N = 2e5+5;

int T, n, a[N];
vector<tuple<int, int> > ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if(n & 1) puts("-1");
		else {
			for(int i = 1; i < n; i += 2) {
				if(a[i] == a[i+1]) ans.emplace_back(i, i+1);
				else {ans.emplace_back(i, i); ans.emplace_back(i+1, i+1);}
			}
			printf("%d\n", (int)ans.size());
			for(auto i : ans) printf("%d %d\n", get<0>(i), get<1>(i));
		}
		ans.clear();
	}
	return 0;
}