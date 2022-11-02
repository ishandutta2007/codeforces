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
	int a[3];
	int b[3];
inline void smax(int &u, int v ) {if(u<v) u =v;}
	int ok(int st) {
		for(int i=0; i<3; i++) b[i] = a[i];
		for(int i=1; i<8; i++) if((st>>i)&1) {
			for(int j=0; j<3; j++) if((i>>j)&1) b[j]--;
		}
		for(int j=0; j<3; j++) if(b[j] < 0) return 0;
		return 1;
	}
int solve() {
	for(int i=0; i<3; i++) cin >> a[i];
	int ans = 0;
	
	for(int i=1; i<1<<8; i++) {
		if(ok(i)) smax(ans, __builtin_popcount(i)-1);
	}
	cout << ans << endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}