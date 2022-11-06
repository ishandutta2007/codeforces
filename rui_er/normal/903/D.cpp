//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef __int128 ll;
const int N = 2e5+5;

int n, a[N];
map<int, int> mp;
ll s[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void write(ll x, char end = 0) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x < 10) putchar(x + 48);
	else {
		write(x / 10);
		putchar(x % 10 + 48);
	}
	if(end) putchar(end);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	per(i, n, 1) {
		++mp[a[i]];
		s[i] = s[i+1] + a[i];
		ans += s[i+1] - (ll)a[i] * (n - i);
		ans += mp[a[i]-1];
		ans -= mp[a[i]+1];
	}
	write(ans, '\n');
	return 0;
}