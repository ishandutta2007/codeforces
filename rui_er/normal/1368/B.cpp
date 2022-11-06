//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 10;
const char s[] = "codeforces";

ll n, a[N];
ll calc() {
	ll res = 1;
	rep(i, 0, 9) res *= a[i];
	return res;
}
void work() {
	ll _ = 0;
	loop {
		++a[_];
		if(calc() >= n) break;
		(++_) %= 10;
	}
}

int main() {
	scanf("%lld", &n); work();
	rep(i, 0, 9) rep(j, 1, a[i]) putchar(s[i]); puts("");
    return 0;
}