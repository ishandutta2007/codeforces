#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 300005;
int a[N];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	int n;
	ll ans = 0;
	in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	sort(a+1, a+1+n);
	for(int i=1; i<=(n >> 1); i++)
		ans += (a[i] + a[n-i+1]) * (a[i] + a[n-i+1]);
	cout << ans << endl;
	return 0;
}