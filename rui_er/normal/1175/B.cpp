//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 4294967295;

ll n, x;
char s[N];
stack<ll> stk, val;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	stk.push(1);
	val.push(0);
	for(scanf("%lld", &n);n;n--) {
		scanf("%s", s+1);
		if(s[1] == 'a') ++val.top();
		else if(s[1] == 'f') {
			scanf("%lld", &x);
			stk.push(x);
			val.push(0);
		}
		else {
			ll x = stk.top(), v = val.top();
			stk.pop(); val.pop();
			val.top() += x * v;
		}
		if(val.top() > inf) return puts("OVERFLOW!!!")&0;
	}
	printf("%lld\n", val.top());
	return 0;
}