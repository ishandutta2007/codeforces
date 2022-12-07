// LUOGU_RID: 93139877
// Problem: C. Complementary XOR
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/C
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

int T, n, a[N], b[N], c[N];
char s[N], t[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%s%s", &n, s+1, t+1);
		rep(i, 1, n) a[i] = s[i] - '0';
		rep(i, 1, n) b[i] = t[i] - '0';
		rep(i, 1, n) c[i] = a[i] ^ b[i];
		if(*min_element(c+1, c+1+n) != *max_element(c+1, c+1+n)) {puts("NO"); continue;}
		puts("YES");
		vector<tuple<int, int> > ans;
		rep(i, 1, n) if(!a[i]) ans.emplace_back(i, i);
		int k = ans.size();
		if((k & 1) == c[1]) {
			ans.emplace_back(1, 1);
			ans.emplace_back(2, n);
		}
		else ans.emplace_back(1, n);
		printf("%d\n", (int)ans.size());
		for(auto i : ans) printf("%d %d\n", get<0>(i), get<1>(i));
	}
	return 0;
}