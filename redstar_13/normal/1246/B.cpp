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

const int NN = 100011;
int a[NN];
map<VI, int> mp;
int n, k;

int solve() {
	cin >> n >> k;
	INT ans = 0;
	for(int i=1; i<=n; i++) {
		int u; scanf("%d", &u);
		int v = u;
		VI a, b;
		for(int j=2; j*j<=v; j++) if(v%j==0) {
			int c = 0;
			while(v%j==0) c++, v/=j;
			if(c%k) {
				a.pb(j);
				a.pb(k-c%k);
				b.pb(j);
				b.pb(c%k);
			}
		}
		if(v > 1) {
			int c=1;
			int j=v;
			a.pb(j);
			a.pb(k-c%k);
			b.pb(j);
			b.pb(c%k);
		}
		ans += mp[b];
		mp[a]++;
	}
	cout << ans << endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}