// LUOGU_RID: 94323334
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll ask(ll x, ll y) {
	++q;
	printf("? %lld %lld\n", x, y);
	fflush(stdout);
	scanf("%lld", &x);
	return x;
}
void give(ll x) {
	printf("! %lld\n", x);
	fflush(stdout);
}

int main() {
	for(ll i = 2; q < 50; i++) {
		ll x = ask(1, i);
		if(x == -1) {give(i - 1); break;}
		if(q == 50) break;
		ll y = ask(i, 1);
		if(x != y) {give(x + y); break;}
	}
	return 0;
}