//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int n;
char s[N];
vector<int> a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	int now = 0, ans = 0;
	rep(i, 1, n) {
		if(s[i] == '0') {
			a[now++].push_back(i);
			chkmax(ans, now);
		}
		else {
			if(!now) return puts("-1")&0;
			a[--now].push_back(i);
		}
	}
	rep(i, 0, ans-1) {
		int pos = a[i].back();
		if(s[pos] == '1') return puts("-1")&0;
	}
	printf("%d\n", ans);
	rep(i, 0, ans-1) {
		int sz = a[i].size();
		printf("%d ", sz);
		for(auto val : a[i]) printf("%d ", val);
		puts("");
	}
	return 0;
}