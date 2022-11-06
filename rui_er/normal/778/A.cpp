// Problem: CF778A String Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF778A
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

char s[N], t[N], str[N];
int n, m, p[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int M) {
	rep(i, 1, n) buc[i] = 0;
	rep(i, 1, M) buc[p[i]] = 1;
	int qwq = 0, j = 1;
	rep(i, 1, n) if(!buc[i]) str[++qwq] = s[i];
	rep(i, 1, qwq) {
		if(str[i] == t[j]) {
			++j;
			if(j > m) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%s%s", s+1, t+1);
	n = strlen(s+1);
	m = strlen(t+1);
	rep(i, 1, n) scanf("%d", &p[i]);
	int L = 0, R = n;
	while(L < R) {
		int M = (L + R) >> 1;
		if(check(M)) L = M + 1;
		else R = M;
	}
	printf("%d\n", L-1);
	return 0;
}