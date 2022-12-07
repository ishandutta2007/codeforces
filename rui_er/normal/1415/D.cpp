// LUOGU_RID: 94428553
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	if(n > 64) return puts("1")&0;
	rep(i, 1, n) s[i] = (s[i-1] ^ a[i]);
	int ans = n;
	rep(i, 1, n) rep(j, i+1, n) rep(k, i, j-1) if((s[k] ^ s[i-1]) > (s[j] ^ s[k])) chkmin(ans, j-i-1);
	printf("%d\n", ans == n ? -1 : ans);
	return 0;
}