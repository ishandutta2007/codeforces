//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n, nxt[N], dp[N];
char s[N];
vector<tuple<int, int> > ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	nxt[1] = 0;
	rep(i, 2, n) {
		int j = nxt[i-1];
		while(j && s[i] != s[j+1]) j = nxt[j];
		if(s[i] == s[j+1]) ++j;
		nxt[i] = j;
	}
	per(i, n, 1) {
		++dp[i];
		dp[nxt[i]] += dp[i];
	}
	for(int i=n;i;i=nxt[i]) {
		ans.push_back(make_tuple(i, dp[i]));
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for(auto i : ans) printf("%d %d\n", get<0>(i), get<1>(i));
	return 0;
}