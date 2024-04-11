//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, s, a[N], b[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &s);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	if(!a[1]) return puts("NO")&0;
	if(!a[s] && !b[s]) return puts("NO")&0;
	if(a[s]) return puts("YES")&0;
	rep(i, s+1, n) if(a[i] && b[i]) return puts("YES")&0;
	return puts("NO")&0;
}