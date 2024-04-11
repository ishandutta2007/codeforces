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

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int t;
	cin >> t;
	while(t--) {
		int n, x, y;
		cin >> n >> x >> y;
		cout << min(n, max(1, x+y-n+1)) << ' ' << max(1, n+1-max(n+2-x-y, 1)) << endl;
	}
	return 0;
}