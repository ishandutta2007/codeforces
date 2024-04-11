//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5; 

int n, L[N], R[N], preL[N], preR[N], sufL[N], sufR[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	memset(preL, ~0x3f, sizeof(preL));
	memset(preR, 0x3f, sizeof(preR));
	memset(sufL, ~0x3f, sizeof(sufL));
	memset(sufR, 0x3f, sizeof(sufR));
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &L[i], &R[i]);
	rep(i, 1, n) preL[i] = max(preL[i-1], L[i]);
	rep(i, 1, n) preR[i] = min(preR[i-1], R[i]);
	per(i, n, 1) sufL[i] = max(sufL[i+1], L[i]);
	per(i, n, 1) sufR[i] = min(sufR[i+1], R[i]);
	rep(i, 1, n) chkmax(ans, min(preR[i-1], sufR[i+1]) - max(preL[i-1], sufL[i+1]));
	printf("%d\n", ans);
	return 0;
}