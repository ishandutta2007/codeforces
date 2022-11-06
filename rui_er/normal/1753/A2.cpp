// LUOGU_RID: 91302076
// Problem: A2. Make Nonzero Sum (hard version)
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforc.es/contest/1753/problem/A2
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
		if(accumulate(a+1, a+1+n, 0) & 1) puts("-1");
		else {
			for(int i = 1; i <= n;) {
				if(i == n) {
					ans.emplace_back(i, i);
					break;
				}
				else if(a[i] == a[i+1]) {
					ans.emplace_back(i, i+1);
					i += 2;
				}
				else if(a[i] && a[i+1]) {
					ans.emplace_back(i, i);
					ans.emplace_back(i+1, i+1);
					i += 2;
				}
				else if(!a[i]) {
					ans.emplace_back(i, i);
					++i;
				}
				else {
					int j = i + 1;
					while(j <= n && !a[j]) ++j;
					int len = (j - 1) - (i + 1) + 1;
					if(a[i] != a[j])ans.emplace_back(i, i),ans.emplace_back(i+1, j-1),ans.emplace_back(j, j);
					else {
						if(len & 1) {
							ans.emplace_back(i, j-2);
							ans.emplace_back(j-1, j);
						}
						else ans.emplace_back(i, j);
					}
					i = j + 1;
				}
			}
			printf("%d\n", (int)ans.size());
			for(auto i : ans) printf("%d %d\n", get<0>(i), get<1>(i));
		}
		ans.clear();
	}
	return 0;
}