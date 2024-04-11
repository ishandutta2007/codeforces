#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}



	INT n, p;
	int w, d;
int solve() {
	cin >> n >> p >> w >> d;
	int g = __gcd(d, w);
	if(p%g) return puts("-1");
	for(int i=0; i<=2*w; i++) {
		INT r = p-w*i;
		if(r<0 or r%d) continue;
		INT c=r/d;
		if(c+i<=n) {
			cout << i<<' '<<c<<' '<<n-c-i<<endl;
			return 0;
		}
	}
	for(int i=0; i<=2*w; i++) {
		INT r = p-d*i;
		if(r<0 or r%w) continue;
		INT c=r/w;
		if(c+i<=n) {
			cout << c<<' '<<i<<' '<<n-c-i<<endl;
			return 0;
		}
	}
	puts("-1");
	
}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}