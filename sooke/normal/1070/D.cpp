#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

int a[200005];
int n, k, now;
ll ans = 0;

int main() {
	cin >> n >> k;
	for(register int i = 1; i <= n; i++) read(a[i]);
	now = a[1];
	for(register int i = 2; i <= n; i++) {
		int t = (now - 1) / k + 1;
		if(now == 0) t = 0;
		now = a[i] + now - t * k;
		ans += (ll)t;
		if(now < 0) now = 0;
	}
	if(!now) cout << ans << endl;
	else cout << ans + (ll)(now - 1) / k + 1ll << endl;
	return 0;
}