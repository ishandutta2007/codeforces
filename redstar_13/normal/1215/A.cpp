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
	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;
	int n;
	cin >> n;
	int mn, mx;
	if(k1>k2) {
		swap(a1, a2);
		swap(k1, k2);
	}
	int r = min(a1, n/k1);
	int m = n-r*k1;
	mx = r + min(m/k2, a2);
	n -= (k1-1) * a1 + (k2-1) * a2;
	mn = max(n, 0);
	cout << mn << ' ' << mx << endl;
		
	return 0;
}