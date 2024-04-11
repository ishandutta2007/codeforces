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

int n, p;

int solve() {
	cin >> n >> p;
	for(int k=1; k<100000; k++) {
		int N = n-k*p;
		int c = __builtin_popcount(N);
		if(N>=0 and c <= k and k<=N) return cout << k << endl, 0;
	}
	return puts("-1");
}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}