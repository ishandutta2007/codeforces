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

int solve() {
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int A = (a + c-1)/c;
	int B = (b + d-1)/d;
	if(A+B>k) return puts("-1");
	cout << A <<' ' <<B<<endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int t;
	cin >> t;
	while(t--) {
			solve();
	}
	return 0;
}